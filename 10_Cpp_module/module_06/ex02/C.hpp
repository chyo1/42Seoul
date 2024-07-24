#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
    public:
        Base* generate();
        void identify(Base* p);
        void identify(Base& p);
};

#endif