#include "../DiamondTrap.hpp"

int	main(void){
	
	DiamondTrap Blood("Blood");
	DiamondTrap Rare("Rare");

	Blood.whoAmI();
	Rare.whoAmI();
	Blood.attack(Rare.GetName());
	Rare.takeDamage(Blood.GetFragAttackDamage());
	Rare.AnnounceStatus();
	Blood.AnnounceStatus();

}