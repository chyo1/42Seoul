#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    PmergeMe pmergeMe;

    try {
        pmergeMe.checkValidInput(argc, argv);
    }catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "Before: ";
    pmergeMe.printArr();

    pmergeMe.mergeSort();

    // std::cout << "After: ";
    // pmergeMe.printArr();

    // std::cout << "Time to process a range of " << argc - 1 << "elements with std::vector :" << std::endl;
    // std::cout << "Time to process a range of " << argc - 1 << "elements with std::[..] :" << std::endl; //

}