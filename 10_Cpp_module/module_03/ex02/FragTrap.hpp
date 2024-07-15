#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const& src);
        FragTrap &operator=(const FragTrap &fixed);
        virtual ~FragTrap();

		virtual void attack(std::string const& target);
        void highFivesGuys();
};

#endif