#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & src);
        ScavTrap &operator=(const ScavTrap &fixed);
        ~ScavTrap();

        void attack(std::string const & target);
        void guardGate();
};

#endif