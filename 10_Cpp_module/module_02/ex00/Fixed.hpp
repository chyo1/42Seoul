#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int fixedPointValue;
        // static -> 내부 선언 불가, static const -> 내부 초기화 가능
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed &operator=(const Fixed &fixed);
        ~Fixed();

        int getRawBits(void) const; // const : 함수 내에서 멤버 변수 변경 불가
        void setRawBits(int const raw);
};

#endif