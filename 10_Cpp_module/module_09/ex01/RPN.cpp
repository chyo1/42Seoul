#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    _s = other._s;
}

RPN &RPN::operator=(const RPN &other) {
    _s = other._s;
    return *this;
}

RPN::~RPN() {}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

long long RPN::run(std::string str) {
    if (str.empty())
        throw std::runtime_error("Error");
    size_t i = -1;
    while (str[++i] == ' ');

    for (; i < str.size(); i++) {
        if (isdigit(str[i]))
            _s.push(str[i] - '0');
        else if (str[i] == ' ')
            continue;
        else if (isOperator(str[i])) {
            _s.push(calculate(str[i]));
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    if (_s.size() != 1)
        throw std::runtime_error("Error");
    return _s.top();
}

long long RPN::calculate(char oper) {
    if (_s.size() < 2)
        throw std::runtime_error("Error");

    long long b = _s.top();
    _s.pop();

    long long a = _s.top();
    _s.pop();

    if (oper == '+')
        return a + b;
    else if (oper == '-')
        return a - b;
    else if (oper == '*')
        return a * b;
    else if (oper == '/') {
        if (b == 0)
            throw std::runtime_error("Division by zero");
        return a / b;
    }
    return 0; //
}

