#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void f() {
	system("leaks exec");
}
int main()
{
    std::cout << "-----------Animal------------" << std::endl;
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    std::cout << "-----------Wrong Animal------------" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    wrongAnimal->makeSound();
	atexit(f);
    return 0;
}