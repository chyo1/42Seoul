#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        ~WrongAnimal();
        void makeSound() const;
        WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
        std::string getType() const;

    protected:
        std::string type;
};

#endif