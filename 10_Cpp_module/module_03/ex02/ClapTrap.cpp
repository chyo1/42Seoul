#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap name constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    std::cout << "ClapTrap copy constructor" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    std::cout << "ClapTrap assignation operator" << std::endl;
    if (this != &clapTrap) {
        this->name = clapTrap.name;
        this->hitPoints = clapTrap.hitPoints;
        this->energyPoints = clapTrap.energyPoints;
        this->attackDamage = clapTrap.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(std::string const& target) {
    if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hitPoints == 100) {
        std::cout << "ClapTrap " << this->name << " is already at full health!" << std::endl;
        return;
    }
     if (this->energyPoints == 0) {
        std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " is being repaired for " << amount << " points!" << std::endl;
    this->hitPoints += amount;
    this->energyPoints -= 1;
}