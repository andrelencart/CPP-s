#include "../HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {
	std::cout << "HumanA: " << _name << " has been Created!!" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << "HumanA: " << _name << " has been DESTROYED!!" << std::endl;
}

void	HumanA::attack(void){
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
} 