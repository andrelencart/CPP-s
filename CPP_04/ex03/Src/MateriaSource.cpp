#include "../MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 2; i++)
		_Materias[i] = NULL;
	std::cout << "A MateriaSource was Created!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy){
	for (int i = 0; i < 2; i++){
		if (copy._Materias[i])
			_Materias[i] = copy._Materias[i]->clone();
		else
			_Materias[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
	if (this != &copy){
		for (int i = 0; i < 2; i++){
			delete _Materias[i];
			_Materias[i] = NULL;
		}
		for (int i = 0; i < 2; i++){
			if (copy._Materias[i])
				_Materias[i] = copy._Materias[i]->clone();
			else
				_Materias[i] = NULL;
	}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 2; i++){
		delete _Materias[i];
		_Materias[i] = NULL;
	}
	std::cout << "The MateriaSource was Destroyed!" << std::endl;
}


void	MateriaSource::learnMateria(AMateria* m){
	if (!m)
		return ;
	
	for (int i = 0; i < 2; i++){
		if (_Materias[i] && _Materias[i]->getType() == m->getType()){
			std::cout << "That Materia Already Known!" << std::endl;
			return ;
		}
	}
	
	AMateria* copy = m;
	if (!copy)
		return ;
	
	for (int i = 0; i < 2; i++){
		if (_Materias[i] == NULL){
			_Materias[i] = copy;
			return ;
		}
	}
	delete copy;
}

AMateria* MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 2; i++){
		if (_Materias[i] && _Materias[i]->getType() == type)
			return _Materias[i]->clone();
	}
	return 0;
}