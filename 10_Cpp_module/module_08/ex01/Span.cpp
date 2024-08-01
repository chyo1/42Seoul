#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const& src) {
    _n = src._n;
    _v = src._v;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_n == _v.size())
        throw std::out_of_range("No more space");
    _v.push_back(n);
}

int Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");
    std::sort(_v.begin(), _v.end());
    int shortestSpan = INT_MAX;
    for (int i = 0; i < static_cast<int>(_v.size()) - 1; i++) {
        if (_v[i + 1] - _v[i] < shortestSpan)
            shortestSpan = _v[i + 1] - _v[i];
    }
    return shortestSpan;
}

int Span::longestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");
    int min = *std::min_element(_v.begin(), _v.end());
    int max = *std::max_element(_v.begin(), _v.end());
    return max - min;
}