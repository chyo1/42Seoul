#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
    protected:
        std::string name;
        unsigned int hitPoints;
        unsigned int energyPoints;
        unsigned int attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const & src);
        ClapTrap &operator=(const ClapTrap &clapTrap);
        virtual ~ClapTrap();

        virtual void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif