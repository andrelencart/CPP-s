#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap{

	private:
		std::string _Name;

	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator = (const ScavTrap& other);
		~ScavTrap();

		int GetScavEnergyPoints();
		void attack(const std::string& target);
		void guardGate();
};

#endif