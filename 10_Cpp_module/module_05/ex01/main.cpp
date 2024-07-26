#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Form formA("formA", 0, 1); //
        std::cout << formA;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;
    
    try {
        Form formB("formB", 1, 0); //
        std::cout << formB;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat bureaucrat("bureaucrat", 20);
        Form formC("formC", 10, 1);
        std::cout << formC;
        
        bureaucrat.signForm(formC);
        formC.beSigned(bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;

    return 0;
}