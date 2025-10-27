#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{

	// private:
	// 	std::string _Name;
	// 	int	_HitPoints;
	// 	int	_EnergyPoints;
	// 	int	_AttackDamage;

	public:
		ScavTrap();
		// ScavTrap(std::string Name);
		// ScavTrap(const ScavTrap& other);
		// ScavTrap& operator = (const ScavTrap& other);
		~ScavTrap();

		void attack(const std::string& target);
};

#endif