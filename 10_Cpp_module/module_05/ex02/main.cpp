#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat b1("b1", 1);
        ShrubberyCreationForm shrubbery("home");
        shrubbery.beSigned(b1);
        shrubbery.execute(b1);

    } catch (const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    } catch (ShrubberyCreationForm::failToOpenFile& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;


    try {
        Bureaucrat b2("b2", 1);
        RobotomyRequestForm robotomy("home2");
        robotomy.beSigned(b2);
        robotomy.execute(b2);

    } catch (const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat b3("b3", 1);
        PresidentialPardonForm presidentialPardon("home3");
        presidentialPardon.beSigned(b3);
        presidentialPardon.execute(b3);

    } catch (const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;

    try {
        Bureaucrat b4("b4", 149);
        ShrubberyCreationForm shrubbery("home4");
        shrubbery.beSigned(b4);
        b4.executeForm(shrubbery);

    } catch (const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------" << std::endl << std::endl;


    return 0;
}