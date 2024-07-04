#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {}

WrongAnimal::WrongAnimal(std::string type) : type(type) {}

WrongAnimal::~WrongAnimal() {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal) {
    this->type = WrongAnimal.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}