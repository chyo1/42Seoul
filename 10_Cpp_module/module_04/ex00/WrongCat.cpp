#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {}

WrongCat::~WrongCat() {}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat) {
	WrongAnimal::operator=(WrongCat);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meowww" << std::endl;
}

std::string WrongCat::getType() const {
    return this->type;
}