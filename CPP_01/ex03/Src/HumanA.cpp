#include "../HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
	_name = name;
	weapon.setType(w);
	std::cout << "HumanA: " << _name << "has been Created!!" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << "HumanA: " << _name << "HumanA has been DESTROYED!!" << std::endl;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}