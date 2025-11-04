#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal{

	protected:
		std::string _type;
		AAnimal(std::string type);

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal& operator = (const AAnimal& other);
		virtual ~AAnimal() = 0;

		virtual void makeSound() const;
		std::string getType() const;
		virtual std::string getIdea(std::size_t idx) const;

};

#endif //AANIMAL_HPP