#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        
        virtual void makeSound() const;
        virtual std::string getType() const;

    protected:
        std::string type;
};

#endif