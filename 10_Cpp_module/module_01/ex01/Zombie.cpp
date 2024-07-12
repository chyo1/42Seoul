#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "Created Zombie" << std::endl;
}

Zombie::Zombie(std::string name) : name(name){
    std::cout << "Created " << name << std::endl;
}

Zombie::~Zombie(){
    std::cout << this->name << " Destroyed" << std::endl;
    // delete this
}

void Zombie::announce(){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}