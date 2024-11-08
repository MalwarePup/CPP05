#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string &name,
	unsigned int grade) : _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : _name(b.getName()),
	_grade(b.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
	if (this != &b)
	{
		*this = Bureaucrat(b);
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == HIGHEST_GRADE)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade++;
}

const char *GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
