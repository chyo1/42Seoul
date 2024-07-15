#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class Materiasource : public IMateriaSource{
    private:
        AMateria* _materias[4];
        int _idx;
    public:
        Materiasource();
        Materiasource(Materiasource const& src);
        Materiasource& operator=(Materiasource const& src);        
        virtual ~Materiasource() {}
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const& type);
};

#endif