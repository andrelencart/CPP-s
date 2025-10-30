#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap{

	protected:
		std::string _Name;

	public:
		DiamondTrap();
		DiamondTrap(std::string Name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator = (const DiamondTrap& other);
		~DiamondTrap();

		void whoAmI();

};

#endif //DIAMONDTRAP_HPP