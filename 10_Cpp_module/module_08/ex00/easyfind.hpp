#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

// 이터레이터 넘기기, 첫번째 나온 위치 반환
template <typename T>
void easyfind(T a, int b) {
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it != a.end()) {
        std::cout << "Value found: " << *it << std::endl;
    } else {
        throw std::invalid_argument("Value not found");
    }
}

#endif