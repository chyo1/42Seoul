#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat= new Cat();

    delete dog; //should not create a leak
    delete cat;

    return 0;
}

