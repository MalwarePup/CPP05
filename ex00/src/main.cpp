#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("John", 1);
		std::cout << b << std::endl;
		for (int i = 0; i < 10; i++)
		{
			b.decrementGrade();
			std::cout << b << std::endl;
		}
		for (int i = 0; i < 11; i++)
		{
			b.incrementGrade();
			std::cout << b << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Jane", 150);
		std::cout << c << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat d("Doe", 0);
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat e("Kristina", 151);
		std::cout << e << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
