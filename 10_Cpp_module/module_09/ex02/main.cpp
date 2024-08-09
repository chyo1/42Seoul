#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char** argv) {
    PmergeMe pmergeMe;

    try {
        pmergeMe.checkValidInputAndPrintInput(argc, argv);
    }catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
}