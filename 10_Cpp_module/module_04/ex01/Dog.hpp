#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;

    public:
        Dog();
        Dog(std::string type);
        ~Dog();
        Dog(const Dog &dog);
        Dog &operator=(const Dog &dog);
        void makeSound() const;
        std::string getType() const;
        void setBrain(std::string str);
        void getBrain() const;
    
};

#endif