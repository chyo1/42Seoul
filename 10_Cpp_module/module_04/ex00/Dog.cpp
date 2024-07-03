#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(std::string type) : Animal(type) {}

Dog::~Dog() {}

Dog &Dog::operator=(const Dog &dog) {
    this->type = dog.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woooof" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}
