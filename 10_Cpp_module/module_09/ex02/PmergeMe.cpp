#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
    _vec = pmergeMe._vec;
    _deq = pmergeMe._deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
    if (this != &pmergeMe) {
        _vec = pmergeMe._vec;
        _deq = pmergeMe._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {
    _vec.clear();
    _deq.clear();
}


void checkIsValidNumber(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) 
            throw std::invalid_argument("Invalid input");
    }
}
void PmergeMe::checkValidInputAndPrintInput(int argc, char** argv) {
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe num1, num2, ...");

    for (int i = 1; i < argc; i++) {
        checkIsValidNumber(argv[i]);
        _vec.push_back(std::stoi(argv[i]));
    }
    std::cout << "Before: ";
    printArr(_vec);
}

template <typename T>
void PmergeMe::printArr(T vec) {
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
