#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

bool PhoneBook::getCommand(std::string &command) {
    std::getline(std::cin, command);
    if (std::cin.eof()) {
        std::cout << "Entered signal" << std::endl;
        EXIT();
    }
    if (command == "") {
        std::cout << "Invalid input" << std::endl;
        return false;
    }
    return true;
}

PhoneBook::PhoneBook() {
    this->contactCount = 0;
}

void PhoneBook::ADD() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string secret;

    std::cout << "Enter first name : ";
    if (!getCommand(firstName))
        return;

    std::cout << "Enter last name : ";
    if (!getCommand(lastName))
        return;

    std::cout << "Enter nickname : ";
    if (!getCommand(nickname))
        return;

    std::cout << "Enter secret code : ";
    if (!getCommand(secret))
        return;

    this->contacts[(this->contactCount) % 8] = Contact((this->contactCount) % 8 + 1, firstName, lastName, nickname, secret);
    this->contactCount++;
}

void PhoneBook::SEARCH() {
    if (this->contactCount == 0) {
        std::cout << "There are no contacts :-(" << std::endl;
        return;
    }
    std::cout << std::endl << "     index|first name| last name|  nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    int end = this->contactCount > 8 ? 8 : this->contactCount;
    for (int i = 0; i < end; i++) {
        this->contacts[i].display();
    }

    std::string idx;
    std::cout << "Enter index : ";
    if (!getCommand(idx))
        return;
    if (idx.length() != 1 || idx[0] < '1' || idx[0] > '8') {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    int index = idx[0] - '0';
    
    std::cout << std::endl << "Searching for contact with index " << index << std::endl << std::endl;
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    this->contacts[index - 1].display();
}

void PhoneBook::EXIT() {
    std::cout << "Exit!" << std::endl;
    exit(0);
}