#include "../Dog.hpp"
#include "../Cat.hpp"

int main()
{
	AAnimal* animals[4];
	// AAnimal A;
	std::size_t n = sizeof(animals) / sizeof(animals[0]);

	for (size_t i = 0; i < n; i++){
		if (i < n / 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}

	for (size_t i = 0; i < n; i++){
		if (i < n / 2)
			animals[i]->makeSound();
		else
			animals[i]->makeSound();
	}

	for (std::size_t i = 0; i < n; ++i) {
		std::cout << "animal[" << i << "] idea[" << i <<"]: " << animals[i]->getIdea(i) << '\n';
	}

	for (size_t i = 0; i < n; i++){
		delete animals[i];
	}

}
