#include <iostream>
#include <string>
#include "Zombie.hpp"

int main() {
    Zombie zombie1 = Zombie("Zombie1");
    zombie1.announce();

    Zombie* zombie2 = newZombie("Zombie2");
    zombie2->announce();
    delete zombie2;

    randomChump("Zombie3");

    return 0;
}