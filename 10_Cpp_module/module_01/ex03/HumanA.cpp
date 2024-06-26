#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) :name(name), weapon(weapon){};

void HumanA::attack(){
    std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}