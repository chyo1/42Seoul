#include "Data.hpp"

Data::Data() {}

Data::Data(Data const &src) {
    *this = src;
}

Data &Data::operator=(Data const &src) {
	if (this != &src) {
		*this = src;
	}
    return *this;
}

Data::~Data() {}