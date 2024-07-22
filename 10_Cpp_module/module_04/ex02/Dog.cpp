#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), brain(new Brain()) {
    std::cout << "Dog type constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &dog) : Animal(dog.type), brain(new Brain(*dog.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &dog) {
	if (this != &dog) {
		this->type = dog.type;
		*this->brain = *dog.brain;
	}
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woooof" << std::endl;
}

std::string Dog::getType() const {
    return this->type;
}

void Dog::setBrain(std::string str) {
    brain->setIdea(str);
}

void Dog::getBrain() const {
    brain->getIdeas();
}