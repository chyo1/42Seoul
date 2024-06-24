#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
}

Contact::Contact(int index, std::string firstName, std::string lastName, std::string nickname, std::string secret) {
    this->index = index;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->secret = secret;
}

// 연락처 출력
void Contact::display() {
    std::cout << std::setw(10) << this->index << "|";
    if (this->firstName.length() > 10) {
        std::cout << this->firstName.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << this->firstName << "|";
    }
    if (this->lastName.length() > 10) {
        std::cout << this->lastName.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << this->lastName << "|";
    }
    if (this->nickname.length() > 10) {
        std::cout << this->nickname.substr(0, 9) << ".|";
    } else {
        std::cout << std::setw(10) << this->nickname << "|";
    }
    std::cout << std::endl << std::endl;
}
