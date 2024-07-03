#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::Cat(std::string type) : Animal(type) {}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &cat) {
    this->type = cat.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}