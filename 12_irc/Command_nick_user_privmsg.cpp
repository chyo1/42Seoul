#include "Channel.hpp"
#include "Error.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include <sstream>
#include <string>
#include <vector>

void Server::command_pass(const int fd, const std::vector<std::string> &cmds) {
    if (cmds[0] != "PASS") {
        return;
    }

    if (cmds.size() < 2) {
        clients_fd[fd].send_message(get_servername(), Error::err_needmoreparams(cmds[0]));
        return;
    }

    if (clients_fd[fd].get_is_authorized() && !clients_fd[fd].get_is_registered()) {
        return;
    }

    const std::string nickname = clients_fd[fd].get_nickname();
    if (clients_fd[fd].get_is_registered()) {
        clients_fd[fd].send_message(get_servername(), Error::err_alreadyregistered(nickname));
        return;
    }

    const std::string entered_password = cmds[1];
    if (entered_password != server_password) {
        clients_fd[fd].send_message(get_servername(), Error::err_passwdmismatch());
        return;
    }

    clients_fd[fd].set_is_authorized();
}

// NICK <new_nickname>
// TODO : client 객체 생성 시 nickname 임의로 지정
void Server::command_nick(const int fd, const std::vector<std::string> &cmds) {
    // not NICK command
    if (cmds[0] != "NICK") {
        return;
    }

    if (!clients_fd[fd].get_is_authorized()) {
        clients_fd[fd].send_message(get_servername(), Error::err_passwdmismatch());
        return;
    }

    // no new_nickname : ERR_NONICKNAMEGIVEN, 431
    if (cmds.size() != 2) {
        clients_fd[fd].send_message(get_servername(), Error::err_nonicknamegiven());
        return;
    }

    // already registered nickname : ERR_NICKNAMEINUSE, 433
    if (clients_nickname.find(cmds[1]) != clients_nickname.end()) {
        clients_fd[fd].send_message(get_servername(), Error::err_nicknameinuse(cmds[1]));
        return;
    }

    // check valid nickname
    for (unsigned long i = 0; i < cmds[1].size(); i++) {
        const char c = cmds[1][i];
        if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_')) {
            clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[1]));
            return;
        }
    }
    if (('0' <= cmds[1][0] && cmds[1][0] <= '9')) {
        clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[1]));
        return;
    }
    // change nickname
    std::map<int, Client>::iterator it = clients_fd.find(fd);
    Client &client = it->second;
    const std::string prev_identifier = client.get_identifier();
    if (!client.get_nickname().empty())
        clients_nickname.erase(client.get_nickname());
    client.set_nickname(cmds[1]);
    clients_nickname[cmds[1]] = &clients_fd[fd];

    if (it->second.get_is_registered()) {
        clients_fd[fd].send_message(prev_identifier, " NICK :" + it->second.get_nickname());
    } else if (!it->second.get_is_registered() && it->second.is_connect_possible()) {
        register_client(fd);
    }
}

void Server::command_user(const int fd, const std::vector<std::string> &cmds) {
    // not USER command
    if (cmds[0] != "USER") {
        return;
    }

    if (!clients_fd[fd].get_is_authorized()) {
        clients_fd[fd].send_message(get_servername(), Error::err_passwdmismatch());
        return;
    }

    // no username : ERR_NEEDMOREPARAMS, 461
    if (cmds.size() != 5 || cmds[1].empty() || cmds[4].empty()) {
        clients_fd[fd].send_message(get_servername(), Error::err_needmoreparams(cmds[0]));
        return;
    }

    // already registered username : ERR_ALREADYREGISTRED, 462
    std::map<int, Client>::iterator it = clients_fd.find(fd);
    if (it->second.get_username() != "") {
        const std::string &nickname = clients_fd[fd].get_nickname();
        clients_fd[fd].send_message(get_servername(), Error::err_alreadyregistered(nickname));
        return;
    }

    // check valid username
    for (unsigned long i = 0; i < cmds[1].size(); i++) {
        const char c = cmds[1][i];
        if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_')) {
            clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[1]));
            return;
        }
    }
    if (('0' <= cmds[1][0] && cmds[1][0] <= '9')) {
        clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[1]));
        return;
    }

    // check valid realname
    for (unsigned long i = 0; i < cmds[4].size(); i++) {
        const char c = cmds[4][i];
        if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || c == '_' || c == ' ')) {
            clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[4]));
            return;
        }
    }
    if (('0' <= cmds[4][0] && cmds[4][0] <= '9')) {
        clients_fd[fd].send_message(get_servername(), Error::err_erroneusnickname(cmds[4]));
        return;
    }

    // change username
    it->second.set_username(cmds[1]);
    it->second.set_realname(cmds[4]);   // TODO: 이름 유효성 검사 해야함

    if (it->second.is_connect_possible()) {
        register_client(fd);
    }
}

static std::vector<std::string> split_recipients(const std::string &arg) {
    std::vector<std::string> recipients;
    std::stringstream ss(arg);
    std::string recipient;

    while (std::getline(ss, recipient, ',')) {
        recipients.push_back(recipient);
    }
    return recipients;
}

void Server::command_privmsg(const int fd, const std::vector<std::string> &cmds) {
    if (!clients_fd[fd].get_is_registered()) {
        clients_fd[fd].send_message(get_servername(), Error::err_notregistered());
        return;
    }

    const std::string command = cmds[0];
    const std::string &nickname = clients_fd[fd].get_nickname();

    if (cmds.size() == 1) {
        clients_fd[fd].send_message(get_servername(), Error::err_norecipient(nickname, command));
        return;
    }

    if (cmds.size() == 2) {
        clients_fd[fd].send_message(get_servername(), Error::err_notexttosend(nickname));
        return;
    }

    const std::string message = cmds[2];
    const std::vector<std::string> recipients = split_recipients(cmds[1]);
    Client &client = clients_fd[fd];

    for (std::vector<std::string>::const_iterator it = recipients.begin(); it != recipients.end(); it++) {
        if (it->rfind("#", 0) != 0) {   // to one person
            const std::string &recipient = *it;

            std::map<std::string, Client*>::iterator iu = clients_nickname.find(recipient);
            if (iu == clients_nickname.end()) {
                clients_fd[fd].send_message(get_servername(), Error::err_nosuchnick(nickname, recipient));
                return;
            }

            iu->second->send_message(client.get_identifier(), "PRIVMSG " + nickname + " :" + message);
        } else {    // to channel
            const std::string &channelname = *it;

            std::map<std::string, Channel>::const_iterator iu = channels.find(channelname);
            if (iu == channels.end()) {
                clients_fd[fd].send_message(get_servername(), Error::err_nosuchnick(nickname, channelname));
                return;
            }

            // 이 유저가 채널에 속해있지 않으면 ERR_CANNOTSENDTOCHAN
            if (iu->second.get_client(&client) == NULL) {
                clients_fd[fd].send_message(get_servername(), Error::err_cannotsendtochan(nickname, channelname));
                return;
            }

            iu->second.send_message(client, "PRIVMSG " + channelname + " :" + message);
        }
    }
}
