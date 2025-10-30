#include "../ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name("Default"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << "ClapTrap " << _Name << " was Created!"<< std::endl; 
}

ClapTrap::ClapTrap(std::string Name): _Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << "ClapTrap " << _Name << " was Created!" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& other){
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << _Name << " was Destroyed!"<< std::endl; 
}

void	ClapTrap::attack(const std::string& target){
	if (this->_EnergyPoints != 0 || this->_HitPoints != 0)
	{
		std::cout << "ClapTrap " << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl; 
		this->_EnergyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << _Name << " received "<< _AttackDamage << " points of damage! " << std::endl; 
	this->_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints != 0 || this->_HitPoints != 0){
		this->_HitPoints += amount;
		this->_EnergyPoints--;
		std::cout << "ClapTrap " << _Name << " received "<< amount << " HitPoints! " << std::endl; 
	}
}

void ClapTrap::AnnounceStatus(){
	std::cout << _Name << ": Energy Points - " << _EnergyPoints << std::endl;
	std::cout << _Name << ": Hit Points - " << _HitPoints << std::endl;
}

std::string ClapTrap::GetClapName(){
	return _Name;
}

int ClapTrap::GetDammage(){
	return _AttackDamage;
}

int ClapTrap::GetHitPoints(){
	return _HitPoints;
}

void ClapTrap::SetDamage(int Damage){
	this->_AttackDamage = Damage;
}

void ClapTrap::SetEnergyPoints(int EnergyPoints){
	this->_EnergyPoints = EnergyPoints;
}

void ClapTrap::SetHitPoints(int HitPoints){
	this->_HitPoints = HitPoints;
}