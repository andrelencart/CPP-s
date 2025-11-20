#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	protected:
		const std::string _Name;
		const int _Grade_to_sign;
		const int _Grade_to_execute;
		bool _Is_signed;

	public:
		AForm();
		AForm(std::string const &name, int grade_S, int grade_E);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm() = 0;


		virtual std::string getName() const;
		virtual int	getGradeToSign() const;
		virtual int	getGradeToExecute() const;
		virtual bool getIsSigned() const;
		virtual bool	beSigned(Bureaucrat &A);
		virtual void executeAction() const = 0;
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};


std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif