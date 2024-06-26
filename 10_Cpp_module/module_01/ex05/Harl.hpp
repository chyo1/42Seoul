#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    private:


    public:
        void debug();
        void info();
        void warning();
        void error();
        void complain(std::string level);

};

#endif
