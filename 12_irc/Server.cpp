#include <sys/event.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include "Server.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "Error.hpp"

static void set_nonblocking(const int sockfd) {
    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
        std::cout << "error\n";
        exit(EXIT_FAILURE);
    }
}

Server::Server(char* port, const std::string password) : server_password(password) {
	if (std::string(port).size() > 6 || std::atoi(port) >= 65536 || std::atoi(port) < 0) {
		std::cout << "error\n";
		exit(EXIT_FAILURE);
	}
	server_port = std::atoi(port);

	create_kqueue();
	if (open_server()) {
		std::cout << "error\n";
		exit(EXIT_FAILURE);
	}
	add_event(server_socket_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
}

std::string Server::get_servername() const {
    return "ircserver";
}

void Server::run() {
	std::cout << "run\n";
	while (true) {
	    set_kqueue_write_event();
		int nev = kevent(kqueue_fd, changelist.data(), changelist.size(),
				eventlist, EVENTLIST_SIZE, NULL);
		changelist.clear();

		if (nev < 0) {
			std::cout << "error\n";
			exit(EXIT_FAILURE);
		}

		for (int i = 0; i < nev; i++) {
			const struct kevent event = eventlist[i];

			if (event.flags & EV_ERROR) {
				std::cout << "error\n";
				exit(EXIT_FAILURE);
			} else if (event.ident == server_socket_fd) {
				struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
				const int client_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
				if (client_fd == -1) {
    				continue;
				}
				set_nonblocking(client_fd);
				char client_ip[INET_ADDRSTRLEN];
				inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
				std::string client_ip_str(client_ip);
				const Client client(client_fd, client_ip_str);
				clients_fd[client_fd] = client;
				add_event(client_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
				add_event(client_fd, EVFILT_WRITE, EV_ADD | EV_DISABLE);
			} else if (event.filter == EVFILT_READ) {
				const int ret = clients_fd[event.ident].read_handler(this);

				if (ret) {
				    remove_client(event.ident);
				}
			} else if (event.filter == EVFILT_WRITE) {
			    const int ret = clients_fd[event.ident].write_handler();

    			if (ret) {
    			    remove_client(event.ident);
    			}
			}
		}
	}
}

void Server::add_event(const uintptr_t ident, const int16_t filter, const uint16_t flags) {
	struct kevent event;

	EV_SET(&event, ident, filter, flags, 0, 0, 0);
	changelist.push_back(event);
}

int Server::create_kqueue() {
	kqueue_fd = kqueue();
	if (kqueue_fd == -1) {
		return -1;
	}

	return 0;
}

int Server::open_server() {
	server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	set_nonblocking(server_socket_fd);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));

	addr.sin_family = AF_INET;
	addr.sin_port = htons(server_port);
	addr.sin_addr.s_addr = INADDR_ANY;

	int optval = 1;
	if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
	    return -1;
	}

	if (bind(server_socket_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
	   return -1;
	}

	listen(server_socket_fd, 1);

	return 0;
}

void Server::set_kqueue_write_event() {
    for (std::map<int, Client>::const_iterator it = clients_fd.begin(); it != clients_fd.end(); it++) {
        const Client client = it->second;

        if (client.is_write_buffer_empty()) {
            add_event(client.get_fd(), EVFILT_WRITE, EV_ADD | EV_DISABLE);
        } else {
            add_event(client.get_fd(), EVFILT_WRITE, EV_ADD | EV_ENABLE);
        }
    }
}

void Server::register_client(const int fd) {
    const std::string &nickname = clients_fd[fd].get_nickname();
    clients_fd[fd].send_message(get_servername(), "001 " + nickname + " :Welcome!");
    clients_fd[fd].set_is_registered();
}

void Server::remove_client(const int fd) {
    for (std::map<std::string, Channel>::iterator it = channels.begin(); it != channels.end(); it++) {
        it->second.remove_client(&clients_fd[fd]);
        it->second.remove_operator(&clients_fd[fd]);
    }
    clients_nickname.erase(clients_fd[fd].get_nickname());
    clients_fd.erase(fd);
    close(fd);

    prune_channel();
}

void Server::prune_channel() {
    for (std::map<std::string, Channel>::iterator it = channels.begin(); it != channels.end(); ) {
        if (it->second.get_clients().empty()) {
			std::map<std::string, Channel>::iterator to_erase = it++;
            channels.erase(to_erase);
        } else {
            it++;
        }
    }
}

void Server::command_parsing(const int fd, const std::string &command) {
    std::string exec_cmd, token;
    std::vector<std::string> tokens;

	if (command.empty())
		return;

    // std::cout << command << '\n';

    // tokenize
    const size_t pos = command.find(':');
    std::string before_colon = command;
    if (pos != std::string::npos) {
        before_colon = command.substr(0, pos);
    }
    std::stringstream ss(before_colon);
    while (ss >> token) {
        tokens.push_back(token);
    }
    if (pos != std::string::npos) {
        const std::string after_colon = command.substr(pos + 1);
        tokens.push_back(after_colon);
    }

    if (!tokens.empty()) exec_cmd = tokens[0];

    if (exec_cmd == "PASS") {
        command_pass(fd, tokens);
    } else if (exec_cmd == "NICK") {
        command_nick(fd, tokens);
    } else if (exec_cmd == "USER") {
        command_user(fd, tokens);
    } else if (exec_cmd == "PRIVMSG") {
        command_privmsg(fd, tokens);
    } else if (exec_cmd == "JOIN") {
		command_join(fd, tokens);
	} else if (exec_cmd == "MODE") {
		command_mode(fd, tokens);
	} else if (exec_cmd == "TOPIC") {
		command_topic(fd, tokens);
	} else if (exec_cmd == "KICK") {
		command_kick(fd, tokens);
	} else if (exec_cmd == "INVITE") {
		command_invite(fd, tokens);
	} else {
	    std::string nickname = clients_fd[fd].get_nickname();
	    if (nickname.empty()) nickname = "*";
	    clients_fd[fd].send_message(get_servername(), Error::err_unknowncommand(nickname, tokens[0]));
	}
}
