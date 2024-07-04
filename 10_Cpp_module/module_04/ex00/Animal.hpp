#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        ~Animal();
        void makeSound() const;
        Animal &operator=(const Animal &animal);
        std::string getType() const;

    protected:
        std::string type;
};

#endif