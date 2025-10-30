#include "../DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	GetFragAttackDamage();
	GetFragHitPoints();
	GetScavEnergyPoints();
	_Name = "Default";
	std::cout << "DiamondTrap: Default was Created!"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name + "_clap_name"){
	GetFragAttackDamage();
	GetFragHitPoints();
	GetScavEnergyPoints();
	_Name = Name;
	std::cout << "DiamondTrap: " << _Name << " was Created!"<< std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: " << _Name << " was Destroyed!"<< std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap& other){
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
	if (this != &other){
		_Name = other._Name;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "The Diamond name is: " << this->_Name << std::endl;
	std::cout << "The ClapTrap name is: " << GetName() << std::endl;
}
