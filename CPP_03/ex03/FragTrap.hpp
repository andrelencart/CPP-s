#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{

	public:
		std::string _Name;

	public:
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(const FragTrap& other);
		FragTrap& operator = (const FragTrap& other);
		~FragTrap();

		std::string	GetName();
		int GetFragHitPoints();
		int GetFragAttackDamage();
		void highFivesGuys(void);

};

#endif