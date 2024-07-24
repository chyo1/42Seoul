#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));
    Base* base = new Base();

    Base* test1 = base->generate();
    base->identify(test1);
    base->identify(*test1);

    Base* test2 = base->generate();
    base->identify(test2);
    base->identify(*test2);

    Base* test3 = base->generate();
    base->identify(test3);
    base->identify(*test3);


    delete test1;
    delete test2;
    delete test3;
    delete base;
    return 0;
}