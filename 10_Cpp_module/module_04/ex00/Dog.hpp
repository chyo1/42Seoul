#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(std::string type);
        ~Dog();
        Dog &operator=(const Dog &dog);
        Dog(const Dog &dog);
        
        void makeSound() const;
};

#endif