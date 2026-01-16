#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string _Name;
		int	_Grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int	getGrade() const;
		void	IncrementGrade(unsigned int nb_increments);
		void	DecrementGrade(unsigned int nb_increments);
		void	SignForm(AForm &A);

		void executeForm(AForm const & form) const;

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