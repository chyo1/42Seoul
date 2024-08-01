#include <iostream>
#include "iter.hpp"
#include <string>

template<typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

template<typename T>
void add(T& value) {
	value += value;
}

int main() {
    std::cout << "------intArray------" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print);
	iter(intArray, 5, add);

    std::cout << "------doubleArray------" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, print);
	iter(doubleArray, 5, add);

    std::cout << "------stringArray------" << std::endl;
    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    iter(stringArray, 5, print);
	iter(stringArray, 5, add);

    return 0;
}
