#include "../FragTrap.hpp"

FragTrap::FragTrap(){
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap: Default was Created!"<< std::endl;
}

FragTrap::FragTrap(std::string Name): ClapTrap(Name){
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	_Name = Name;
	std::cout << "FragTrap: " << _Name << " was Created!"<< std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: " << _Name << " was Destroyed!"<< std::endl; 
}

FragTrap::FragTrap(const FragTrap& other){
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other){
		_Name = other._Name;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void){
	std::cout << "Please give me a High Five I'm DESPERATE!!!" << std::endl;
}
