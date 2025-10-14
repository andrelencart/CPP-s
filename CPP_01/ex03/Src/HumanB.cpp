#include "../HumanB.hpp"

HumanB::HumanB(std::string name){
	_name = name;
	std::cout << "HumanB: " << _name << "has been Created!!" << std::endl;
}

HumanB::~HumanB(void){
	std::cout << "HumanB: " << _name << "HumanB has been DESTROYED!!" << std::endl;
}

void	HumanB::attack(void){
	// if (this->_weapon.getType().empty())

}