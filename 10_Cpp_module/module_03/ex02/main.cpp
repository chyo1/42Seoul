#include "FragTrap.hpp"

int main() {

    FragTrap hyowchoi("hyowchoi");
    FragTrap target("target");

    hyowchoi.attack("target");
    target.takeDamage(30);
    hyowchoi.beRepaired(80);

    hyowchoi.attack("target");
    hyowchoi.takeDamage(30);

    hyowchoi.highFivesGuys();

    return 0;
}