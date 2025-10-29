#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{

	protected:
		std::string _Name;
		int	_HitPoints;
		int	_EnergyPoints;
		int	_AttackDamage;

	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator = (const ClapTrap& other);
		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void AnnounceStatus();
		
		std::string	GetName();
		int	GetDammage();
		int	GetHitPoints();

		void	SetDamage(int Damage);
		void	SetHitPoints(int HitPoints);
		void	SetEnergyPoints(int EnergyPoints);

};

#endif