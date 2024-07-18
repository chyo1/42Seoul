#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
    std::cout << "Dog type constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog::Dog(const Dog &dog) : Animal(dog.type) {
    *this = dog;
    brain = new Brain(*dog.brain);
}

Dog &Dog::operator=(const Dog &dog) {
    this->type = dog.type;
    this->brain = dog.brain;
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