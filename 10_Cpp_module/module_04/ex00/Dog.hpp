#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog();
        Dog(std::string type);
        virtual ~Dog();
        Dog &operator=(const Dog &dog);
        virtual void makeSound() const;
        std::string getType() const;
};

#endif