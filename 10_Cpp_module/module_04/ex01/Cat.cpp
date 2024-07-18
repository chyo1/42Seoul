#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type), brain(new Brain()) {
    std::cout << "Cat type constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &cat) : Animal(cat.type), brain(new Brain(*cat.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
	if (this == &cat)
		return *this;
    this->type = cat.type;
	*this->brain = *cat.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}

std::string Cat::getType() const {
    return this->type;
}

void Cat::setBrain(std::string str) {
    brain->setIdea(str);
}

void Cat::getBrain() const {
    brain->getIdeas();
}