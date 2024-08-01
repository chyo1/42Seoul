#include <iostream>
#include "iter.hpp"
#include <string>

template<typename T>
void print(T const &value) {
    std::cout << value << std::endl;
}

int main() {
    std::cout << "------intArray------" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print);

    std::cout << "------doubleArray------" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, print);

    std::cout << "------stringArray------" << std::endl;
    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    iter(stringArray, 5, print);

    return 0;
}
