#include "../Base.hpp"

Base::~Base(){
	std::cout << "Base Destroyed!" << std::endl;
}

Base *Base::generate(void){

}

void	Base::identify(Base *p){

}

void	Base::identify(Base& p){

}

Base *	Base::generate(void){

	int random_gen = rand() % 3;

	if (random_gen == 0)
		return new A();
	else if (random_gen == 1)
		return new B();
	else
		return new C();
}