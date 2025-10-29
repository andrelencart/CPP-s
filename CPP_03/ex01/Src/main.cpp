#include "../ScavTrap.hpp"

int	main(void){
	ScavTrap One("One");
	ScavTrap Two("Two");

	One.attack(Two.GetName());
	Two.takeDamage(One.GetDammage());
	Two.AnnounceStatus();
	One.AnnounceStatus();
	One.guardGate();
	Two.beRepaired(5);
	Two.AnnounceStatus();

}