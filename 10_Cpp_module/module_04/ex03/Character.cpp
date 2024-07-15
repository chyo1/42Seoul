#include "Character.hpp"

Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(std::string const& name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(Character const & src) {
    *this = src;
}

Character::~Character() {
    delete[] _inventory;
}
Character& Character::operator=(Character const & src) {
    _name = src._name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = new AMateria(&src._inventory[i]);
    return *this;
}

std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

