#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {}

Cat::Cat(std::string type) : Animal(type) {}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &cat) {
	Animal::operator=(cat);
    return *this;
}

Cat::Cat(const Cat &cat) : Animal(cat) {}

void Cat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}