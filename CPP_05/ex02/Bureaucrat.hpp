#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		std::string const _Name;
		int	_Grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int	getGrade() const;
		void	IncrementGrade(int nb_increments);
		void	DecrementGrade(int nb_increments);
		void	SignForm(Form &A);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif