#ifndef SERVER_HPP
#define SERVER_HPP

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <sys/event.h>

#include "Channel.hpp"
#include "Client.hpp"

#define EVENTLIST_SIZE 8

class Server {
public:
	Server(char* port, std::string password);

	void run();
	void command_parsing(const int fd, const std::string &command);

private:
	std::map<std::string, Channel> channels;
	std::map<std::string, Client*> clients_nickname; // nickname -> client
	std::map<int, Client> clients_fd; // fd -> client

	const std::string server_password;
	int server_port;

	std::vector<struct kevent> changelist;
	struct kevent eventlist[EVENTLIST_SIZE];

	int kqueue_fd;
	unsigned int server_socket_fd;

	std::string get_servername() const;

	int create_kqueue();
    void set_kqueue_write_event();
	int open_server();
	void add_event(const uintptr_t ident, const int16_t filter, const uint16_t flags);

	void register_client(const int fd);
	void remove_client(const int fd);

	void prune_channel();

	void command_pass(const int fd, const std::vector<std::string> &cmds);
	void command_nick(const int fd, const std::vector<std::string> &cmds);
	void command_user(const int fd, const std::vector<std::string> &cmds);
	void command_privmsg(const int fd, const std::vector<std::string> &cmds);

	void command_join(const int fd, std::vector<std::string> &cmds);
	void command_topic(const int fd, const std::vector<std::string> &cmds);
	void command_invite(const int fd, const std::vector<std::string> &cmds);
	void command_kick(const int fd, std::vector<std::string> &cmds);

	void command_mode(const int fd, const std::vector<std::string> &cmds);
};

#endif
