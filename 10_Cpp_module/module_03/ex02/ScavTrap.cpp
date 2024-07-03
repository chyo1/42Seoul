#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap name constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &clapTrap) {
    std::cout << "ScavTrap assignation operator" << std::endl;
    if (this != &clapTrap) {
        this->name = clapTrap.name;
        this->hitPoints = clapTrap.hitPoints;
        this->energyPoints = clapTrap.energyPoints;
        this->attackDamage = clapTrap.attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor" << std::endl;
}

void ScavTrap::attack(std::string const & target){
    if (this->energyPoints == 0) {
        std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}
