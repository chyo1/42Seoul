#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat b1("b1", 150);
        ShrubberyCreationForm shrubbery("home");
        // shrubbery.beSigned(b1);
        // shrubbery.execute(b1);

        b1.executeForm(shrubbery);

    } catch (const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}