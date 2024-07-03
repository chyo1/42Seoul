#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

    public:
        Cat();
        Cat(std::string type);
        virtual ~Cat();
        virtual void makeSound() const;
        Cat &operator=(const Cat &cat);

        std::string getType() const;
};

#endif