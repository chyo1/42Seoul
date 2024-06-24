#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
    this->contactCount = 0;
}

void PhoneBook::ADD() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string secret;

    // EOF 처리 printf, cin 둘 다 처리해줘야 댐
    std::cout << "Enter first name : ";
    std::getline(std::cin, firstName);
    if (firstName == "") {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    std::cout << "Enter last name : ";
    std::getline(std::cin, lastName);
    if (lastName == "") {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    std::cout << "Enter nickname : ";
    std::getline(std::cin, nickname);
    if (nickname == "") {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    std::cout << "Enter secret code : ";
    std::getline(std::cin, secret);
    if (secret == "") {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    this->contacts[(this->contactCount) % 8] = Contact((this->contactCount) % 8 + 1, firstName, lastName, nickname, secret);
    this->contactCount++;
}

void PhoneBook::SEARCH() {
    std::cout << std::endl << "     index|first name| last name|  nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    
    int end = this->contactCount > 8 ? 8 : this->contactCount;
    for (int i = 0; i < end; i++) {
        this->contacts[i].display();
    }
    int index;
    std::cout << "enter index : ";
    std::cin >> index;
    if (index < 1 || index > end) {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    
    std::cout << std::endl << "Searching for contact with index " << index << std::endl << std::endl;
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    this->contacts[index - 1].display();
}

void PhoneBook::EXIT() {
    std::cout << "Exit!" << std::endl;
}