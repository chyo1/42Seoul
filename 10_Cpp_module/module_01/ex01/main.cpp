#include <iostream>
#include <string>
#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = zombieHorde(3, "zom");

    for (int i = 0; i < 3; i++) {
        zombie1[i].announce();
    }
    
    delete[] zombie1;
    return 0;
}