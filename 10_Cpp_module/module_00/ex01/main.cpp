#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD/SEARCH/EXIT) : ";;
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            phoneBook.EXIT();
            break;
        }
        if (command == "ADD") {
            phoneBook.ADD();
        } else if (command == "SEARCH") {
            phoneBook.SEARCH();
        } else if (command == "EXIT") {
            phoneBook.EXIT();
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}