#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat &operator=(const WrongCat &WrongCat);
        ~WrongCat();

        void makeSound() const;
        std::string getType() const;
};

#endif