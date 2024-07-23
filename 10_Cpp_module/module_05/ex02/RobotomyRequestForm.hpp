#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const& src);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
        virtual ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const& executor) const;
};

#endif