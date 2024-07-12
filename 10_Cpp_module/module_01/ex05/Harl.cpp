#include "Harl.hpp"
#include <iostream>

void Harl::debug() {
    std::cout << "--------------------------------------[DEBUG LEVEL]--------------------------------------" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
    std::cout <<  "I really do!" << std::endl << std::endl;;
}

void Harl::info() {
    std::cout << "---------------------------------------[INFO LEVEL]--------------------------------------" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout <<  "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout <<  "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;;
}

void Harl::warning() {
    std::cout << "-------------------------------------[WARNING LEVEL]-------------------------------------" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout <<  "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;;
}

void Harl::error() {
    std::cout << "--------------------------------------[ERROR LEVEL]--------------------------------------" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) {
    
    struct Level {
        std::string level;
        // 반환값, 매개변수가 없는 함수 포인터 선언
        void (Harl::*func)();
    };

    Level levels[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };

    // 배열을 순회하며 level에 해당하는 함수를 호출
    for (int i = 0; i < 4; i++) {
        if (levels[i].level == level) {

            // 저장된 함수 포인터를 통해 함수 호출
            (this->*levels[i].func)();
            return;
        }
    }

    std::cout << "Invalid level: " << level << std::endl;
}