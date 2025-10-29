#include "../ScavTrap.hpp"

ScavTrap::ScavTrap(){
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap: Default was Created!"<< std::endl;
}


ScavTrap::ScavTrap(std::string Name): ClapTrap(Name){
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_Name = Name;
	std::cout << "ScavTrap: " << _Name << " was Created!"<< std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: " << _Name << " was Destroyed!"<< std::endl; 
}

ScavTrap::ScavTrap(const ScavTrap& other){
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	if (this != &other){
		_Name = other._Name;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (GetHitPoints() != 0 || GetHitPoints() != 0){
		std::cout << "ScavTrap " << _Name << " attacks " << target << " causing " << GetDammage() << " points of damage!" << std::endl; 
		_EnergyPoints--;
	}
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap: " << _Name << " is now in Gate keeper mode." << std::endl;
}