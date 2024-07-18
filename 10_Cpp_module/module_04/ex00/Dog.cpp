#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(std::string type) : Animal(type) {}

Dog::~Dog() {}

Dog &Dog::operator=(const Dog &dog) {
	Animal::operator=(dog);
    return *this;
}

Dog::Dog(const Dog &dog) : Animal(dog) {}

void Dog::makeSound() const {
    std::cout << "Woooof" << std::endl;
}

