#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat {
    private:
        const std::string _name;
        int _grade; // 1 ~ 150
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const& src);
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& src);

        void incrementGrade();
        void decrementGrade();
        std::string getName() const;
        int getGrade() const;
        void signForm(AForm* form);

        void executeForm(AForm const& form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FailedExecuteForm : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& src);

#endif