#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal{

	private:
		Brain _ideas;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator = (const Dog& other);
		~Dog();

		void makeSound() const;
		virtual std::string getIdea(std::size_t idx) const;

};

#endif //DOG_HPP