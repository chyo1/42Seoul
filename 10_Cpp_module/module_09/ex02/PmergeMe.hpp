#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
class PmergeMe {
    private:
        std::vector< std::pair<int, int> > _vec;
        std::deque< std::pair<int, int> > _deq; //
        size_t _numberCnt;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);

        void checkValidInput(int argc, char** argv);
        void devideAndGetPair();
        void mergeSort();

        void printArr();
        int getNumberCnt();
};

#endif