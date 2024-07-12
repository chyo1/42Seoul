#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::HumanB(std::string name, Weapon& weapon) : name(name), weapon(&weapon) {}

void HumanB::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}