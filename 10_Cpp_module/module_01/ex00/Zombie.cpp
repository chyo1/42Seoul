#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "Created Zombie" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " Created" << std::endl;
}

Zombie::~Zombie(){
    std::cout << this->name << " Destroyed" << std::endl;
}

void Zombie::announce(){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}