#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& a, int b) {
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end()) {
        throw std::invalid_argument("Value not found");
    }
    return it;
}

template <typename T>
typename T::iterator easyfind(const T& a, int b) {
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end()) {
        throw std::invalid_argument("Value not found");
    }
    return it;
}

#endif