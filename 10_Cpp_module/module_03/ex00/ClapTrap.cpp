#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap parameter constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
    std::cout << "ClapTrap copy constructor" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &fixed) {
    std::cout << "ClapTrap assignation operator" << std::endl;
    if (this != &fixed) {
        this->name = fixed.name;
        this->hitPoints = fixed.hitPoints;
        this->energyPoints = fixed.energyPoints;
        this->attackDamage = fixed.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor" << std::endl;
}

void ClapTrap::attack(std::string const& target) {

}

void ClapTrap::takeDamage(unsigned int amount) {
    this->hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    this->hitPoints += amount;
}