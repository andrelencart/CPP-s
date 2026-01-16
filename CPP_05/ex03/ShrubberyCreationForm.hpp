#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();


		// std::string getName() const;
		// int	getGradeToSign() const;
		// int	getGradeToExecute() const;
		// bool getIsSigned() const;
		// bool	beSigned(Bureaucrat &A);

		void executeAction() const;

};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& b);

#endif