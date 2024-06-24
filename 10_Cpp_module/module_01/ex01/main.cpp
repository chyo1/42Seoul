#include <iostream>
#include <string>
#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = zombieHorde(3, "zom");
    delete[] zombie1;
    return 0;
}