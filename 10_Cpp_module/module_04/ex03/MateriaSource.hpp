#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource{
    private:
        AMateria* _materias[4];
        int _idx;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const& src);
        MateriaSource& operator=(MateriaSource const& src);        
        virtual ~MateriaSource() {}

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const& type);
};

#endif