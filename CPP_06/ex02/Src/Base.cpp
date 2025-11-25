#include "../Base.hpp"
#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"

Base::~Base(){
	std::cout << "Base Destroyed!" << std::endl;
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

void Base::identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C" << std::endl;
}

void Base::identify(Base &p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference to A" << std::endl;
		return;
	} catch(std::exception &e){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference to B" << std::endl;
		return;
	} catch(std::exception &e){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference to C" << std::endl;
		return;
	} catch(std::exception &e){}
}