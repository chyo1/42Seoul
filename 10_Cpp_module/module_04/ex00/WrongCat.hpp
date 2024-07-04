#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat();
        WrongCat(std::string type);
        ~WrongCat();
        void makeSound() const;
        WrongCat &operator=(const WrongCat &WrongCat);
        std::string getType() const;
};

#endif