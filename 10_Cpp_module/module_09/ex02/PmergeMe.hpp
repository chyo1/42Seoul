#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <cstddef>
class PmergeMe {
    private:
        std::vector<int> _arr;
        std::vector< std::pair<int, int> > _vec;
        std::list< std::pair<int, int> > _list; //
        size_t _numberCnt;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);

        void checkValidInput(int argc, char** argv);
        int devideAndGetPair();
        void mergeSortVec();
        void mergeSortList();

        void printArr();
        void printVec();
        void printList();
};

#endif