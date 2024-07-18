#include "Character.hpp"
#include "AMateria.hpp"
Character::Character() : _name("default") {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
        _floor[i] = NULL;
    }
}

Character::Character(std::string const& name) : _name(name) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
        _floor[i] = NULL;
    }
}

Character::Character(Character const & src) {
    *this = src;
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete _inventory[i];
        delete _floor[i];
    }
}

Character& Character::operator=(Character const& src) {
    _name = src._name;
    _invenIdx = src._invenIdx;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = src._inventory[i] ? src._inventory[i]->clone() : NULL;
        _floor[i] = src._floor[i] ? src._floor[i]->clone() : NULL;
    }
    return *this;
}

std::string const& Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) {
    if (_invenIdx < 4)
        _inventory[_invenIdx++] = m;
}

void Character::unequip(int idx) {
    if (_floorIdx < 4)
        _floor[_floorIdx++] = _inventory[idx--];
}

void Character::use(int idx, ICharacter& target) {
    _inventory[idx]->use(target);
}

