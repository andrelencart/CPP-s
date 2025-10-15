
#include "../Weapon.hpp"

Weapon::Weapon(std::string type){
	_type = type;
	std::cout << "Weapon has been Created!!" << std::endl;
}

// Weapon::Weapon(void){
// 	std::cout << "Weapon has been Created!!" << std::endl;
// }


Weapon::~Weapon(void){
	std::cout << "Weapon has been DESTROYED!!" << std::endl;
}

void	Weapon::setType(std::string type){
	this->_type = type;
}

std::string Weapon::getType(void){
	return this->_type;
}