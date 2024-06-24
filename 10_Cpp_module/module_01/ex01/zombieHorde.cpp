#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde(int N, std::string name) {
    Zombie* retZombie = new Zombie[N]; 

    for (int i = 0; i < N; i++) {
        retZombie[i].setName(name);
    }
    return retZombie;
}