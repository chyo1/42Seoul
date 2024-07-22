#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Form highGrade("highGrade", 0, 0);
        std::cout << highGrade;

    } catch (const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        Form lowGrade("lowGrade", 151, 1);
        std::cout << lowGrade;

    } catch (const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form test("test", 1, 1);
        std::cout << test;

    } catch (const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

     try {
        Bureaucrat bureaucrat("bureaucrat", 1);
        Form form("form", 1, 1);
        form.beSigned(bureaucrat);
        bureaucrat.signForm(form);

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}