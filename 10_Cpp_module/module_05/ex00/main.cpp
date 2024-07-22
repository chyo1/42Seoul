#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    try {
        Bureaucrat hyowchoi("hyowchoi", 1);

        Bureaucrat highGrade("highGrade", 0);
        Bureaucrat lowGrade("lowGrade", 151);

    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cout << ;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << ;
    } catch (...) {
        
    }

    return 0;
}