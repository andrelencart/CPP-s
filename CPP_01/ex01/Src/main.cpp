#include "../Zombie.hpp"

int	main(void){
	int	n = 5;
	Zombie	*new_z;

	new_z = zombieHorde(n, "Zumbi");

	delete[] new_z;
}