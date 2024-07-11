#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        Animal &operator=(const Animal &animal);
        Animal(const Animal &animal);
        void makeSound() const;
        std::string getType() const;

    protected:
        std::string type;
};

#endif