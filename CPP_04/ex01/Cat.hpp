#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{

	private:
		Brain *_ideas;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator = (const Cat& other);
		~Cat();

		void makeSound() const;
		virtual std::string getIdea(std::size_t idx) const;
};

#endif //CAT_HPP