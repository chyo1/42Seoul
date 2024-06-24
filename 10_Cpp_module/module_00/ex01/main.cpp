#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD/SEARCH/EXIT) : ";
        phoneBook.getCommand(command);

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