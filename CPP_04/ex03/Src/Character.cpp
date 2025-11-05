#include "../Character.hpp"

Character::Character(): _Name("Unknown"){
	for (int i = 0; i < 4; i++)
		_SpellSlot[i] = NULL;
	std::cout << "A Character was Created!" << std::endl;
}

Character::Character(std::string const name): _Name(name){
	for (int i = 0; i < 4; i++)
		_SpellSlot[i] = NULL;
	std::cout << "Character: " << _Name << " was Created!" << std::endl;
}

Character::Character(const Character& copy): _Name(copy._Name){
	for (int i = 0; i < 4; i++){
		if (copy._SpellSlot[i])
			_SpellSlot[i] = copy._SpellSlot[i]->clone();
		else
			_SpellSlot[i] = NULL;
	}
}

Character& Character::operator=(const Character& copy){
	if (this != &copy){
		for (int i = 0; i < 4; i++){
			delete _SpellSlot[i];
			_SpellSlot[i] = NULL;
		}
		_Name = copy._Name;
		for (int i = 0; i < 4; i++){
			if (copy._SpellSlot[i])
				_SpellSlot[i] = copy._SpellSlot[i]->clone();
			else
				_SpellSlot[i] = NULL;
	}
	}
	return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		delete _SpellSlot[i];
		_SpellSlot[i] = NULL;
	}
	std::cout << "The Character was Destroyed!" << std::endl;
}

std::string const& Character::getName()const{
	return _Name;
}

void	Character::equip(AMateria* m){
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++){
		if (_SpellSlot[i] == NULL){
			_SpellSlot[i] = m;
			std::cout << _SpellSlot[i]->getType() << " was Equipped!" << std::endl;
			return ;
		}

	} 
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 4)
		return ;
	_SpellSlot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 4)
		return ;

	if (_SpellSlot[idx])
		_SpellSlot[idx]->use(target);
}
