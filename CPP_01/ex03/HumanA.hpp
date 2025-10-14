#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "Weapon.hpp"


class HumanA {
	
	public:
	HumanA(std::string name, Weapon weapon);
	~HumanA(void);

	void	HumanA::attack(void);
	
	private:
	Weapon _weapon;
	std::string _name;
	
};

#endif