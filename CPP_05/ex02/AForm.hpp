#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		std::string const _Name;
		const int _Grade_to_sign;
		const int _Grade_to_execute;
		bool _Is_signed;

	public:
		Form();
		Form(std::string const &name, int grade_S, int grade_E);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();


		std::string getName() const;
		int	getGradeToSign() const;
		int	getGradeToExecute() const;
		bool getIsSigned() const;
		bool	beSigned(Bureaucrat &A);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif