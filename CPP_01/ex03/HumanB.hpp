#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "Weapon.hpp"


class HumanB {
	
	public:
	HumanB(std::string name);
	~HumanB(void);
	
	void	HumanB::attack(void);
	void	HumanB::setWeapon(Weapon weapon);
	
	private:
	Weapon _weapon;
	std::string _name;
	
};

#endif