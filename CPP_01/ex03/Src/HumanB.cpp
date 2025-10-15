#include "../HumanB.hpp"

HumanB::HumanB(std::string name){
	_name = name;
	std::cout << "HumanB: " << _name << " has been Created!!" << std::endl;
}

HumanB::~HumanB(void){
	std::cout << "HumanB: " << _name << " has been DESTROYED!!" << std::endl;
}

void	HumanB::attack(void){
	std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;

}

void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}