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

    // std::clock() : 프로그램이 실행된 후의 CPU 시간을 반환, 반환값은 시스템이 시작된 이후로 소모된 클럭 틱의 수를 나타냄
    std::clock_t startVecSec = std::clock();
    pmergeMe.mergeSortVec();
    std::clock_t endVecSec = std::clock();

    std::clock_t startListSec = std::clock();
    pmergeMe.mergeSortList();
    std::clock_t endListSec = std::clock();

    std::cout << "After: ";
    pmergeMe.printVec();

    // 시간 단위로 변환
    double vecTime = static_cast<double> (endVecSec - startVecSec) / CLOCKS_PER_SEC;
    // 백만 곱하기 -> 마이크로초로 변환
    vecTime *= 1e6;

    double listTime = static_cast<double> (endListSec - startListSec) / CLOCKS_PER_SEC;
    listTime *= 1e6;

    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << listTime << " us" << std::endl;

}