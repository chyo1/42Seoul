#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

    public:
        Cat();
        Cat(std::string type);
        ~Cat();
        Cat(const Cat &cat);
        Cat &operator=(const Cat &cat);
        void makeSound() const;
        std::string getType() const;

    private:
        Brain *brain;
};

#endif