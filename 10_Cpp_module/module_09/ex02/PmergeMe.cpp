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
void PmergeMe::checkValidInput(int argc, char** argv) {
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe num1, num2, ...");

    for (int i = 1; i < argc; i++) {
        checkIsValidNumber(argv[i]);
        _vec.push_back(std::make_pair( std::stoi(argv[i]), 0) );
        _deq.push_back(std::make_pair( std::stoi(argv[i]), 0) );
    }
    _numberCnt = argc - 1;
}

void PmergeMe::printArr() {
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i].first << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::devideAndGetPair() {
    size_t pow2 = 1;
    
    while (_numberCnt > pow2)
        pow2 *= 2;

    // 2의 제곱으로 전체 배열의 크기 맞추기
    for (size_t i = 0; i < pow2 - _numberCnt; i++) {
        _vec.push_back( std::make_pair(-1, 0) );
        _deq.push_back( std::make_pair(-1, 0) );
    }

    // 인덱스 pair 맞춰주기
    size_t term = 1;
    while (term < pow2) {
        for (size_t j = 0; j < pow2 - term; j += term * 2) {
            if (_vec[j] < _vec[j + term]) {
                for (size_t k = 0; k < term; k++) {
                    std::swap(_vec[j + k], _vec[j + term + k]);
                }
            }
        }
        term *= 2;
    }

    // 현재 인덱스를 pair에 저장
    for (size_t i = 0; i < pow2; i++)
        _vec[i].second = i;

}

void PmergeMe::mergeSort() {
    devideAndGetPair();
    // printArr();
}