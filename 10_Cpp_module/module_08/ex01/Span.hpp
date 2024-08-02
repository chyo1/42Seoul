#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector> 
class Span {
    private:
        unsigned int _n;
        std::vector<int> _v;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& src);
        ~Span();
        Span& operator=(const Span& span);

        void addNumber(int n);

        template <typename Iter>
        void addNumbers(Iter begin, Iter end, unsigned int n);
        long long shortestSpan();
        long long longestSpan();
};

#endif