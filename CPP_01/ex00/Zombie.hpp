
#ifndef CONTACT_H
# define CONTACT_H

#include <iomanip>
#include <iostream>
#include <cstdlib>


class Zombie {
	
	public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	
	void announce( void );
	
	private:
	std::string name;
	
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif