#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
// #include "ICharacter.hpp"

class Ice: public AMateria{
	
	protected:

	public:
		Ice();
		Ice(const Ice& copy);
		Ice& operator=(const Ice& copy);
		~Ice();

		Ice* clone()const;
		void use(ICharacter& target);

};

#endif