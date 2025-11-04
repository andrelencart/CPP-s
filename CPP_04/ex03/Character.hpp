#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter{
	
	protected:

	public:
		Character();
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		virtual ~Character();
};

#endif