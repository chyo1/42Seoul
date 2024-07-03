#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

// 입력 & 입력값 검증
bool PhoneBook::getCommand(std::string &command) {
    std::getline(std::cin, command);

    // EOF 입력 시 종료
    if (std::cin.eof()) {
        std::cout << "Entered signal" << std::endl;
        EXIT();
    }

    // 입력값이 없을 경우
    if (command == "") {
        std::cout << "Invalid input" << std::endl;
        return false;
    }
    return true;
}

PhoneBook::PhoneBook() {
    this->contactCount = 0;
}

// 연락처 추가
void PhoneBook::ADD() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
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

    std::cout << "Enter phone number : ";
    if (!getCommand(phoneNumber))
        return;
    
    for (size_t i = 0; i < phoneNumber.size(); i++) {
        if(!isnumber(static_cast<char>((phoneNumber[i])))) {
            std::cout << "enter only number" << std::endl;
            return;
        }
    }

    std::cout << "Enter secret code : ";
    if (!getCommand(secret))
        return;

    // 연락처 저장
    this->contacts[(this->contactCount) % 8] = Contact((this->contactCount) % 8 + 1, firstName, lastName, nickname, phoneNumber, secret);
    this->contactCount++;
}

void PhoneBook::SEARCH() {

    // 연락처가 없을 경우
    if (this->contactCount == 0) {
        std::cout << "There are no contacts :-(" << std::endl;
        return;
    }

    // 연락처 출력
    std::cout << "-------------------------------------------------------" << std::endl;
    int end = this->contactCount > 8 ? 8 : this->contactCount;
    for (int i = 0; i < end; i++) {
        this->contacts[i].display();
        std::cout << std::endl;
    }

    // 연락처 선택
    std::string idx;
    std::cout << "Enter index : ";
    if (!getCommand(idx))
        return;

    // 입력받은 인덱스 검증
    if (idx.length() != 1 || idx[0] < '1' || idx[0] > '8' || idx[0] - '0' > this->contactCount) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    // 선택한 연락처 출력
    int index = idx[0] - '0';
    std::cout << std::endl << "Searching for contact with index " << index << std::endl << std::endl;
    std::cout << std::endl << "     index|first name| last name|  nickname|  phoneNum|     secret" << std::endl;
    std::cout << "------------------------------------------------------------------" << std::endl;

    this->contacts[index - 1].displayDetail();
}

void PhoneBook::EXIT() {
    std::cout << "Exit!" << std::endl;
    exit(0);
}