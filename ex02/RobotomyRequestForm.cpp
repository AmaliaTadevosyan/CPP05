#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("Robotomy", 72, 45)
{
    std::cout << "RobotomyRequestForm parameter constructor" << std::endl;
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form("Robotomy", 72, 45)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;
    _target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment operator" << std::endl;
    if (this != &other)
    {
        Form::operator= (other);
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor"  << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getIsSigned())
        throw FormNotSigned();
    if (executor.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::srand(0);
    int randomNum = rand() % 50;
    if (randomNum % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully 50\% of the time." << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}