#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string _name;
        int    _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string _name, int _grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat &other);

        std::string getName() const;
        void setGrade(int grade);
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        class GradeTooHighExeption: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &outputStream, const Bureaucrat &ref);

#endif