#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Created Zombie" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << name << " Created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " Destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}