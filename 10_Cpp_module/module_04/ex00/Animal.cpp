#include "Animal.hpp"

Animal::Animal() : type("Animal") {}

Animal::Animal(std::string type) : type(type) {}

Animal::~Animal() {}

Animal &Animal::operator=(const Animal &animal) {
    this->type = animal.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}