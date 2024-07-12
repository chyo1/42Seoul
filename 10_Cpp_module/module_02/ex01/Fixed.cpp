#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor with int parameter
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << fractionalBits;
}

// Constructor with float parameter
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << fractionalBits));
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

/* --------------------------------------------------------------- */
int Fixed::getRawBits(void) const {
    // std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->fixedPointValue = raw;
}

int Fixed::toInt(void) const {
    return this->fixedPointValue >> fractionalBits;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
    // 1 >> fractionalBits 로 하면 0이 나옴
}

/* << 연산자 오버로딩 함수
   특정 클래스의 객체를 출력할 때 원하는 형식으로 출력할 수 있도록 하는 방법
*/
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}