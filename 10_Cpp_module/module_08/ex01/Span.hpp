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
        Span(Span const & src);
        ~Span();
        Span & operator=(Span const & rhs);

        void addNumber(int n);

        template <typename Iter>
        void addNumbers(Iter begin, Iter end, unsigned int n);
        long long shortestSpan();
        long long longestSpan();
};

#endif