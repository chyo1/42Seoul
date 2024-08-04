#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const& src) {
    _size = src._size;
    _v = src._v;
}

Span& Span::operator=(Span const& span) {
    if (this != &span) {
        _size = span._size;
        _v = span._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_size == _v.size())
        throw std::out_of_range("No more space");

    _v.push_back(n);
}

template <typename Iter>
void Span::addNumbers(Iter begin, Iter end) {
    unsigned int inputSize = std::distance(begin, end);
    if (_size < _v.size() + inputSize)
        throw std::out_of_range("No more space");

    for (Iter it = begin; it != end; it++)
        _v.push_back(*it);
}

unsigned int Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");

    std::sort(_v.begin(), _v.end());

    unsigned int shortestSpan = UINT_MAX;
    for (unsigned int i = 0; i < static_cast<unsigned int>(_v.size()) - 1; i++) {
        if (static_cast<unsigned int>(_v[i + 1] - _v[i]) < shortestSpan)
            shortestSpan = static_cast<unsigned int>(_v[i + 1] - _v[i]);
    }
    return shortestSpan;
}

unsigned int Span::longestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");

    std::sort(_v.begin(), _v.end());
    return _v.back() - _v.front();
}

