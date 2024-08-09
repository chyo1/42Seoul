#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
    private:
        std::stack<long long> _s;

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

        long long run(std::string str);
        long long calculate(char oper);

};

#endif