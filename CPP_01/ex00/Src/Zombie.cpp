
#include "../Zombie.hpp"

Zombie::Zombie(){
	name = "Zumbi";
	announce();
}

Zombie::Zombie(std::string name){
	this->name = name;
	announce();
}

Zombie::~Zombie(){
	std::cout << this->name << ": Has Been DESTROYED!!" << std::endl;
}

void	Zombie::announce( void ){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}