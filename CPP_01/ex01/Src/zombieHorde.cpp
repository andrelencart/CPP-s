#include "../Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	Zombie *new_z = new Zombie[N];

	for (int i = 0; i < N; ++i){
		new_z[i].NameSetter(name);
	}
	return (new_z);
}


