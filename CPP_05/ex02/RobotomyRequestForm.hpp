#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

		void executeAction() const;

};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& b);

#endif