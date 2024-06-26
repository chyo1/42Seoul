#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string type) : type(type) {}

const std::string& Weapon::getType() {
    return this->type;
}

void Weapon::setType(std::string type) {
    this->type = type;
}