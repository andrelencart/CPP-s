#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
// #include "ICharacter.hpp"

class Cure: public AMateria{
	
	protected:

	public:
		Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& copy);
		~Cure();

		Cure* clone()const;
		void use(ICharacter& target);
};

#endif