#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    public:
        void debug();
        void info();
        void warning();
        void error();
        void complain(std::string level);

};

#endif
