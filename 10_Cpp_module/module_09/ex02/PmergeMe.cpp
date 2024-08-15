#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

typedef std::pair<int, int> pi;
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &pmergeMe) {
    _vec = pmergeMe._vec;
    _list = pmergeMe._list;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &pmergeMe) {
    if (this != &pmergeMe) {
        _vec = pmergeMe._vec;
        _list = pmergeMe._list;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// int stringToInt(const std::string& str) {
//     std::stringstream ss(str);
//     int result;
//     ss >> result;

//     // Check for errors: if the stream fails or there are remaining characters in the string
//     if (ss.fail() || !ss.eof()) {
//         throw std::runtime_error("Error");
//     }

//     return result;
// }

int stringToInt(const std::string& str) {
    char* end;
    long value = std::strtol(str.c_str(), &end, 10);

    // Check if the entire string was parsed
    if (*end != '\0') {
        throw std::invalid_argument("Error");
    }

    // Check for overflow and underflow
    if (value > INT_MAX || value < INT_MIN) {
        throw std::out_of_range("Error");
    }

    return static_cast<int>(value);
}

void checkIsValidNumber(std::string str) {
    if (str.empty())
        throw std::invalid_argument("Error");
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) 
            throw std::invalid_argument("Error");
    }
}
void PmergeMe::checkValidInput(int argc, char** argv) {
    if (argc < 2)
        throw std::invalid_argument("Usage: ./PmergeMe num1, num2, ...");

    try {
        for (int i = 1; i < argc; i++) {
            checkIsValidNumber(argv[i]);
            _arr.push_back(stringToInt(argv[i]));
        }
        _numberCnt = argc - 1;
    } catch (const std::exception& e) {
        throw std::invalid_argument(e.what());
    }
}

void PmergeMe::printArr() {
    for (size_t i = 0; i < _arr.size(); i++) {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printVec() {
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i].first << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printList() {
    for (std::list<pi>::iterator it = _list.begin(); it != _list.end(); it++)
        std::cout << it->first << " ";
    std::cout << std::endl;
}

int PmergeMe::devideAndGetPair() {
    size_t pow2 = 1;
    
    while (_numberCnt > pow2)
        pow2 *= 2;

    // 2의 제곱으로 전체 배열의 크기 맞추기
    for (size_t i = 0; i < pow2 - _numberCnt; i++) {
        _arr.push_back(-1);
    }

    // 인덱스 pair 맞춰주기
    size_t term = 1;
    while (term < pow2) {
        for (size_t j = 0; j < pow2 - term; j += term * 2) {
            if (_arr[j] < _arr[j + term]) {
                for (size_t k = 0; k < term; k++) {
                    std::swap(_arr[j + k], _arr[j + term + k]);
                }
            }
        }
        term *= 2;
    }
    return pow2 / 2;
}

bool cmp(pi a, pi b) { return a.first <= b.first; }

void PmergeMe::mergeSortVec() {
    int pairLoc = devideAndGetPair();
    // printArr(); //
    std::vector<pi> mainPairArr, mainSingleArr;
    
    // 메이저 배열 저장
    _vec.push_back( std::make_pair(_arr[0], 0) );

    while (pairLoc > 0) {
        // std::cout << "pairLoc " << pairLoc << std::endl;
        //  printVec(); //
        
        // 메인 배열 생성
        for (size_t i = 0; i < _vec.size(); i++) {
            size_t subIdx = _vec[i].second + pairLoc;

            // std::cout << "mainVal " << _vec[i].first << " subVal " << _arr[subIdx] << std::endl;
            // 짝이 없으면 single, 있으면 pair
            if (_arr[subIdx] < 0)
                mainSingleArr.push_back(_vec[i]);
            else
                mainPairArr.push_back(_vec[i]);
        }

        // _vec에서 singleArr 삭제
        for (size_t i = 0; i < mainSingleArr.size(); i++)
            _vec.erase(std::find(_vec.begin(), _vec.end(), mainSingleArr[i]));

        // std::cout << "rm single thing" << std::endl;
        //  printVec(); //


        // 야콥스타일 수 구하기, 그 수부터 앞으로 넣기
        int startIdx = 0, jacobStyle = 0;
        while (startIdx < static_cast<int>(mainPairArr.size())) {
            for (int i = startIdx + jacobStyle; i >= startIdx; i--) {
                // std::cout << i << " " << pairLoc << std::endl;//
                int minorIdx = mainPairArr[i].second + pairLoc;

                // 값 넣을 범위 탐색
                std::vector<pi>::iterator mainPairLoc = std::find(_vec.begin(), _vec.end(), mainPairArr[i]);
                mainPairLoc++;

                // begin() ~ majorPair의 범위에서 cmp 함수 기준으로 minorPair보다 작은 값을 찾은 후, 해당 자리에 minorPair 삽입
                pi minorPair = std::make_pair(_arr[minorIdx], minorIdx);
                _vec.insert(std::lower_bound(_vec.begin(), mainPairLoc, minorPair, cmp), minorPair);
            }

            startIdx += (jacobStyle + 1);
            int befSize = startIdx * 2 + 1, nowSize = mainPairArr.size() - startIdx - 1;
            jacobStyle = std::pow(2, std::floor(log2(befSize)) + 1) - befSize - 1;

            // 0 < jacobStyle number < nowSize
            jacobStyle = std::max(jacobStyle, 0);
            jacobStyle = std::min(jacobStyle, nowSize);
            
        }
        for (size_t i = 0; i < mainSingleArr.size(); i++) 
            _vec.insert(std::lower_bound(_vec.begin(), _vec.end(), mainSingleArr[i], cmp), mainSingleArr[i]);

        // pair 위치 조정
        pairLoc /= 2;
        mainPairArr.clear();
        mainSingleArr.clear();
        // printVec(); //
    }
}

void PmergeMe::mergeSortList() {
    int pairLoc = devideAndGetPair();
    
    std::list<pi> mainPairList, mainSingleList;
    
    // 메이저 배열 저장
    _list.push_back(std::make_pair(_arr[0], 0));

    while (pairLoc > 0) {
        // 메인 리스트 생성
        for (std::list<pi>::iterator it = _list.begin(); it != _list.end(); ++it) {
            size_t subIdx = it->second + pairLoc;

            // 짝이 없으면 single, 있으면 pair
            if (_arr[subIdx] < 0)
                mainSingleList.push_back(*it);
            else
                mainPairList.push_back(*it);
        }

        // _list에서 singleList 삭제
        for (std::list<pi>::iterator it = mainSingleList.begin(); it != mainSingleList.end(); ) {
            std::list<pi>::iterator found = std::find(_list.begin(), _list.end(), *it);
            if (found != _list.end())
                _list.erase(found);
            it++;
        }

        // 야콥스타일 수 구하기, 그 수부터 앞으로 넣기
        int startIdx = 0, jacobStyle = 0;
        while (startIdx < static_cast<int>(mainPairList.size())) {
            for (int i = startIdx + jacobStyle; i >= startIdx; i--) {
                std::list<pi>::iterator it = mainPairList.begin();
                std::advance(it, i);

                int minorIdx = it->second + pairLoc;

                // 값 넣을 범위 탐색
                std::list<pi>::iterator mainPairLoc = std::find(_list.begin(), _list.end(), *it);
                ++mainPairLoc;

                // begin() ~ majorPair의 범위에서 cmp 함수 기준으로 minorPair보다 작은 값을 찾은 후, 해당 자리에 minorPair 삽입
                pi minorPair = std::make_pair(_arr[minorIdx], minorIdx);
                _list.insert(std::lower_bound(_list.begin(), mainPairLoc, minorPair, cmp), minorPair);
            }

            startIdx += (jacobStyle + 1);
            int befSize = startIdx * 2 + 1, nowSize = mainPairList.size() - startIdx - 1;
            jacobStyle = std::pow(2, std::floor(log2(befSize)) + 1) - befSize - 1;

            // 0 < jacobStyle number < nowSize
            jacobStyle = std::max(jacobStyle, 0);
            jacobStyle = std::min(jacobStyle, nowSize);
        }

        for (std::list<pi>::iterator it = mainSingleList.begin(); it != mainSingleList.end(); ++it) {
            _list.insert(std::lower_bound(_list.begin(), _list.end(), *it, cmp), *it);
        }

        // pair 위치 조정
        pairLoc /= 2;
        mainPairList.clear();
        mainSingleList.clear();
    }
}
