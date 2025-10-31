#include "../Dog.hpp"
#include "../Cat.hpp"
#include "../WrongCat.hpp"

int main()
{
	Animal* animals[10];
	std::size_t n = sizeof(animals) / sizeof(animals[0]);

	for (size_t i = 0; i < n; i++){
		if (i < n / 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	

	for (size_t i = 0; i < n; i++){
		delete animals[i];
	}

	
}
