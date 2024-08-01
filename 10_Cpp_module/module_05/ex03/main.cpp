#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {

    Intern intern;
    AForm *form = NULL;
    try {
        form = intern.makeForm("ShrubberyCreationForm", "home");
        delete form;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;


    try {
        AForm* form = intern.makeForm("RobotomyRequestForm", "home2");
        delete form;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;

    try {
        AForm* form = intern.makeForm("PresidentialPardonForm", "home3");
        delete form;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;

    try {
        AForm* form = intern.makeForm("UnknownForm", "home4");
        delete form;

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl << std::endl;

    return 0;
}