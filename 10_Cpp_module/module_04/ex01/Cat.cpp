#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    Brain *brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(const Cat &cat) {
    this->type = cat.type;
    this->brain = cat.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}