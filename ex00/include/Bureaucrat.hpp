#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include <string>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat
{
	private:
		const std::string _name;
		unsigned int _grade;
	public:
		Bureaucrat() {};
		Bureaucrat(const std::string &name, unsigned int grade);
		Bureaucrat(const Bureaucrat &b);
		Bureaucrat &operator=(const Bureaucrat &b);
		~Bureaucrat() {};

		const std::string &getName() const;
		unsigned int getGrade() const;
};

class GradeTooHighException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif /* BUERAUCRAT_HPP */
