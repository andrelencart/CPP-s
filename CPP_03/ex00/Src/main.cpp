#include "../ClapTrap.hpp"

int	main(){
	ClapTrap Bob("Bob");
	ClapTrap Fred("Fred");

	Bob.AnnounceStatus();
	Fred.AnnounceStatus();
	Bob.attack(Fred.GetName());
	Fred.takeDamage(Bob.GetDammage());
	Fred.AnnounceStatus();
	Fred.beRepaired(2);
	Fred.AnnounceStatus();
}