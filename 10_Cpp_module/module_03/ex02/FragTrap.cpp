#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap name constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &clapTrap) {
    std::cout << "FragTrap assignation operator" << std::endl;
    if (this != &clapTrap) {
        this->name = clapTrap.name;
        this->hitPoints = clapTrap.hitPoints;
        this->energyPoints = clapTrap.energyPoints;
        this->attackDamage = clapTrap.attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}