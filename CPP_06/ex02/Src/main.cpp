#include "../A.hpp"
#include "../B.hpp"
#include "../C.hpp"

int main(void){

	srand(time(NULL));

	std::cout << "=== Testing random generation and identification ===" << std::endl;

	Base* obj1 = Base::generate();
	Base* obj2 = Base::generate();
	Base* obj3 = Base::generate();


	std::cout << "\nIdentify by pointer:" << std::endl;
	std::cout << "obj1: ";
	Base::identify(obj1);
	std::cout << "obj2: ";
	Base::identify(obj2);
	std::cout << "obj3: ";
	Base::identify(obj3);

	std::cout << "\nIdentify by reference:" << std::endl;
	std::cout << "obj1: ";
	Base::identify(*obj1);
	std::cout << "obj2: ";
	Base::identify(*obj2);
	std::cout << "obj3: ";
	Base::identify(*obj3);

	std::cout << std::endl;

	delete obj1;
	delete obj2;
	delete obj3;
	
}