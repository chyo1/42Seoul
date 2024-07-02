#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

        // 비교 연산자 오버로딩
        bool operator>(const Fixed &fixed);
        bool operator<(const Fixed &fixed);
        bool operator>=(const Fixed &fixed);
        bool operator<=(const Fixed &fixed);
        bool operator==(const Fixed &fixed);
        bool operator!=(const Fixed &fixed);

        // 산술 연산자 오버로딩
        Fixed &operator+(const Fixed &fixed);
        Fixed &operator-(const Fixed &fixed);
        Fixed &operator*(const Fixed &fixed);
        Fixed &operator/(const Fixed &fixed);

        // 전위 증감 연산자 오버로딩
        Fixed &operator++(void);
        Fixed &operator--(void);

        // 후위 증감 연산자 오버로딩
        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(const int raw);
        int toInt(void) const;
        float toFloat(void) const;

        static Fixed &min(Fixed &a, Fixed &b);
        // const 함수는 const 함수만 호출 가능
        static const Fixed &min(const Fixed &a, const Fixed &b);
        
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif