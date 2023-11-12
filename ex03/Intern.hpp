#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        Form* makeForm(std::string formName, std::string targetName);
        class NotExistingForm : public std::exception {
                public:
                        const char* what() const throw();
        };
};

#endif