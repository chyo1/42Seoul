#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;

    public:
        Cat();
        Cat(std::string type);
        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        void makeSound() const;
        std::string getType() const;
        void setBrain(std::string str);
        void getBrain() const;

};

#endif