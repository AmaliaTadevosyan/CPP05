#include "PresidentialPardonForm.hpp"
#include <iostream>
#include "Form.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential", 25, 5), _target("Default")
{
    std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("Presidential", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm parameter constructor" << std::endl;
    // _target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form("Presidential", 25, 5)
{
    std::cout <<  "PresidentialPardonForm copy constructor" << std::endl;
    _target = other._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignment operator" << std::endl;
    if (this != &other)
    {
        Form::operator=(other);
        _target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();
   
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}