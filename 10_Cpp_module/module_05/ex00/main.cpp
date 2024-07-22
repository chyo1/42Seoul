#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat highGrade("highGrade", 0);
        std::cout << highGrade;

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        Bureaucrat lowGrade("lowGrade", 151);
        std::cout << lowGrade;

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat test("test", 1);
        std::cout << test;

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}