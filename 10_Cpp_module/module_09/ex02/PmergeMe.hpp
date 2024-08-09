#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq; //

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);

        void checkValidInputAndPrintInput(int argc, char** argv);
        void merge(int *arr, int l, int m, int r);
        void mergeSort(int *arr, int l, int r);

        template <typename T>
        void printArr(T vec);
};

#endif