#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0){
    for (int i = 0; i < 4; i++) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const& src) {
    *this = src;
    for (int i = 0; i < 4; i++) {
        _materias[i] = new AMateria(src._materias[i]);
    }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src) {

}

void MateriaSource::learnMateria(AMateria* m) {
    _materias[_idx] = m;
    _idx = (_idx + 1) % 4;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    
    return new AMateria(type);
}