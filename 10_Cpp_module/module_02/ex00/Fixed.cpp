#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
    /* * 붙이는 이유? -> this가 Fixed* type 포인터이기 때문에
    *this : 이 포인터가 가리키는 실제 객체를 의미
    *this = fixed : 이 객체에 fixed 객체를 할당
    this : 현재 객체 참조, 이를 통해 할당 연산자 호출
    */
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        setRawBits(fixed.getRawBits());
    return *this;
}

// Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}