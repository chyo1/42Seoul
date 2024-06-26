#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main(){

    Weapon club1 = Weapon("crude spiked club");
    HumanA bob("Bob", club1);
    bob.attack();
    club1.setType("some other type of club");
    std::cout << club1.getType() << std::endl;
    bob.attack();

    Weapon club2 = Weapon("crude spiked club");

    HumanB jim("Jim");
    jim.setWeapon(club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();

    return 0;
}