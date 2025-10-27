#include "../ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_ScavTrap"){
	std::cout << "ScavTrap: " << " was Created!"<< std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap: " << " was Destroyed!"<< std::endl; 
}