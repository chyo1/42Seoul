#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0) {
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const& src) {
	*this = src;
    for (int i = 0; i < 4; i++) {
        _materias[i] = src._materias[i] ? new AMateria(*src._materias[i]) : NULL;
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {
	_idx = src._idx;
    for (int i = 0; i < 4; i++) {
        _materias[i] = src._materias[i] ? new AMateria(*src._materias[i]) : NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    _materias[_idx] = new AMateria(m);
    _idx = (_idx + 1) % 4;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    
    return new AMateria(type);
}
