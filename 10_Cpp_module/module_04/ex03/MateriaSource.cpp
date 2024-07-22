#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : _idx(0) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const& src) {
	*this = src;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
	_idx = src._idx;
    for (int i = 0; i < 4; i++) {
        _materias[i] = src._materias[i] ? src._materias[i]->clone() : NULL;
    }
    return *this;
}

MateriaSource:: ~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_materias[i])
			delete _materias[i];
	}
}


void MateriaSource::learnMateria(AMateria* m) {
    _materias[_idx] = m;
    _idx = (_idx + 1) % 4;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    if (type == "ice")
        return new Ice();
    else if (type == "cure")
        return new Cure();
    else
        return 0;
}
