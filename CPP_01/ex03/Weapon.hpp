#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iomanip>
#include <iostream>
#include <cstdlib>


class Weapon {
	
	public:
	// Weapon(void);
	Weapon(std::string type);
	~Weapon(void);
	void setType(std::string type);
	std::string getType(void);
	
	private:
	std::string _type;
	
};

#endif