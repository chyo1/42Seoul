#include "ScavTrap.hpp"

int main() {

    ScavTrap hyowchoi("hyowchoi");
    ScavTrap target("target");

    hyowchoi.attack("target");
    target.takeDamage(20);
    hyowchoi.beRepaired(80);

    hyowchoi.attack("target");
    hyowchoi.takeDamage(20);
    hyowchoi.guardGate();

    return 0;
}