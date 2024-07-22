#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

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

        std::string getName() const;
        int getGrade() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif