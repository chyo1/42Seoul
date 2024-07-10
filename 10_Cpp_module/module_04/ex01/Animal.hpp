#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        ~Animal();
        Animal(const Animal &animal);
        Animal &operator=(const Animal &animal);
        void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};

#endif