#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate() {
    srand(time(NULL));
    int random = rand() % 3;
    if (random == 0) {
        return new A();
    } else if (random == 1) {
        return new B();
    } else {
        return new C();
    }
}

void Base::identify(Base* p) {
    std::cout << "Pointer is pointing to ";

    if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;

	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;

	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;

    std::cout << "type.";
}

void Base::identify(Base& p) {
    std::cout << "Reference is pointing to ";

    try {
        p = dynamic_cast<A&>(p);
        std::cout << "A type." << std::endl;
    } catch (std::bad_cast& e) {}

    try {
        p = dynamic_cast<B&>(p);
        std::cout << "B type." << std::endl;
    } catch (std::bad_cast& e) {}

    try {
        p = dynamic_cast<C&>(p);
        std::cout << "C type." << std::endl;
    } catch (std::bad_cast& e) {}

}