#include "../Dog.hpp"
#include "../Cat.hpp"
#include "../WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;

	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();

	std::cout << w->getType() << " " << std::endl;
	w->makeSound();
	wrongmeta->makeSound();

	delete wrongmeta;
	delete w;

	return 0;
}
