#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Default Constructor is called" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Copy Constructor is called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Copy Assignment Operator called" << std::endl;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Destructor is called " << std::endl;
}

const char* Intern::NotExistingForm::what() const throw() {
    return "Form name does not exist";
}

Form* Intern::makeForm(std::string formName, std::string targetName) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;
    for (int i = 0; i < 3; i++)
        if (formName == formNames[i])
            index = i;

    switch (index) {
        case 0:
            std::cout << "Intern creates ShrubberyCreationForm form " << std::endl;
            return new ShrubberyCreationForm(targetName);
        case 1:
            std::cout << "Intern creates RobotomyRequest form " << std::endl;
            return new RobotomyRequestForm(targetName);
        case 2:
            std::cout << "Intern creates PresidentialPardon form " << std::endl;
            return new PresidentialPardonForm(targetName);
        default:
            throw NotExistingForm();
    }
}