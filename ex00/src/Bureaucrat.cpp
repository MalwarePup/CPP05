#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) :
	_name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	_name = b.getName();
	_grade = b.getGrade();
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
	{
		_name = b.getName();
		_grade = b.getGrade();
	}
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

unsigned int Bureaucrat::getGrade() const
{
	return _grade;
}

const char *GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char * GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
