#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *animals[10];
    for (int i = 0; i < 10; i++) {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    for (int i = 0; i < 10; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 10; i++)
        delete animals[i];

    /*---------------------------------*/
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

    delete dog;
    delete cat; //
    return 0;
}

