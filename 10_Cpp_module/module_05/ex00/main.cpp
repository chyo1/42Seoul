#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat highGrade("highGrade", 1);
        std::cout << highGrade;
        highGrade.incrementGrade();

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat lowGrade("lowGrade", 151);
        std::cout << lowGrade;
        lowGrade.decrementGrade();

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat lowGrade("lowGrade", 151);
        std::cout << lowGrade;
        lowGrade.decrementGrade();

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}