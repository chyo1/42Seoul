#include "Dog.hpp"
#include "Cat.hpp"
#define SIZE 10
int main()
{
    Animal *animals[SIZE];
    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (int i = 0; i < SIZE; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < SIZE; i++)
        delete animals[i];

    std::cout << "----------------------------------------" << std::endl;
    Dog *dog = new Dog();
    dog->setBrain("I am a dog");

    Dog dog2(*dog);
    dog2.setBrain("I am a dog2");

    dog->getBrain();
    dog2.getBrain();

    Cat *cat = new Cat();
    cat->setBrain("I am a cat");

    Cat cat2(*cat);
    cat2.setBrain("I am a cat2");

    cat->getBrain();
    cat2.getBrain();

    delete cat;
    delete dog;
;
    return 0;
}

