#include "ClapTrap.hpp"

int main() {

    ClapTrap hyowchoi("hyowchoi");
    ClapTrap target("target");

    hyowchoi.attack("target");
    target.takeDamage(5);
    hyowchoi.beRepaired(80);
    hyowchoi.attack("target");
    hyowchoi.takeDamage(12);
    return 0;
    
}