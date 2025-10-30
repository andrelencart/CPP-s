#include "../FragTrap.hpp"

int	main(void){
	
	FragTrap One("One");
	FragTrap Two("Two");

	One.attack(Two.GetName());
	Two.takeDamage(One.GetDammage());
	Two.AnnounceStatus();
	One.AnnounceStatus();
	One.highFivesGuys();
	Two.beRepaired(5);
	Two.AnnounceStatus();

}