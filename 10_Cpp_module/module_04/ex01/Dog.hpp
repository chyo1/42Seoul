#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

    public:
        Dog();
        Dog(std::string type);
        ~Dog();
        Dog &operator=(const Dog &dog);
        void makeSound() const;
        std::string getType() const;
    
    private:
        Brain *brain;
};

#endif