#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Form* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

        Form *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Jack");

        Form *ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Hack");

        Form *nef;
        nef = someRandomIntern.makeForm("hello", "Blah Blah");
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}