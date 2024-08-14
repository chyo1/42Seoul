#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

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

    std::clock_t startVecSec = std::clock();
    pmergeMe.mergeSortVec();
    std::clock_t endVecSec = std::clock();

    std::clock_t startListSec = std::clock();
    pmergeMe.mergeSortList();
    std::clock_t endListSec = std::clock();

    std::cout << "After: ";
    pmergeMe.printVec();

    double vecTime = static_cast<double> (endVecSec - startVecSec) / CLOCKS_PER_SEC;
    vecTime *= 1e6;
    double listTime = static_cast<double> (endListSec - startListSec) / CLOCKS_PER_SEC;
    listTime *= 1e6;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << listTime << " us" << std::endl;

}