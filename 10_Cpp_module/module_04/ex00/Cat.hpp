#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

    public:
        Cat();
        Cat(std::string type);
        ~Cat();
        Cat &operator=(const Cat &cat);
        Cat(const Cat &cat);
        
        void makeSound() const ;
        std::string getType() const;
};

#endif