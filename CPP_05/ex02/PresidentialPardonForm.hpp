#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		void executeAction() const;

};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b);

#endif