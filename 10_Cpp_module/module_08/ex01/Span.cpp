#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const& src) {
    _n = src._n;
    _v = src._v;
}

Span& Span::operator=(Span const& span) {
    if (this != &span) {
        _n = span._n;
    _v = span._v; // 깊은 복사 하면 안댐 왜?

        // std::copy(span._v.begin(), span._v.end(), _v.begin());
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
    if (_n == _v.size())
        throw std::out_of_range("No more space");

    _v.push_back(n);
}

// 크기 받지 말고 내가 계산, 표준 라이브러리 확인
template <typename Iter>
void Span::addNumbers(Iter begin, Iter end, unsigned int n) {
    if (_n < _v.size() + n)
        throw std::out_of_range("No more space");

    for (Iter it = begin; it != end; it++)
        _v.push_back(*it);
// back_inserter 써보기
}

long long Span::shortestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");

    std::sort(_v.begin(), _v.end());
	// unsigned int 범위로 다 바꾸기 인덱스, 최댓값 등
    int shortestSpan = INT_MAX;
    for (int i = 0; i < static_cast<unsigned int>(_v.size()) - 1; i++) {
        if (_v[i + 1] - _v[i] < shortestSpan)
            shortestSpan = _v[i + 1] - _v[i];
    }
    return shortestSpan;
}

long long Span::longestSpan() {
    if (_v.size() < 2)
        throw std::out_of_range("Not enough elements, no span can be found");

    std::sort(_v.begin(), _v.end());
    return _v.back() - _v.front();
}

