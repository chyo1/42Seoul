#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    Fixed c;
    Fixed const d;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    
    
    std::cout << Fixed::max(a, c) << std::endl;
    std::cout << Fixed::min(a, c) << std::endl;

    std::cout << Fixed::max(b, d) << std::endl;
    std::cout << Fixed::min(b, d) << std::endl;

    return 0;
}