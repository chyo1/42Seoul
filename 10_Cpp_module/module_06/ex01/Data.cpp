#include "Data.hpp"

Data::Data() : a(0) {}

Data::Data(int a) : a(a) {}

Data::Data(Data const &src) : a(src.a) {
    *this = src;
}

Data &Data::operator=(Data const &src) {
	if (this != &src) {
		*this = src;
	}
    return *this;
}

Data::~Data() {}

int Data::getA() const {
	return a;
}