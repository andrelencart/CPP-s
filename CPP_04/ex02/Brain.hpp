#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{

	protected:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator = (const Brain& other);
		virtual ~Brain();

		void setIdea(std::size_t idx, const std::string& idea);
		std::string getIdea(std::size_t idx) const;
};

#endif //BRAIN_HPP