#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
class Character : public ICharacter{
    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria* _floor[4];
		int _invenIdx;
        int _floorIdx;
    public:
        Character();
        Character(std::string const& name);
        Character(Character const& src);
        virtual ~Character();
        
        Character& operator=(Character const & src);
        virtual std::string const& getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif