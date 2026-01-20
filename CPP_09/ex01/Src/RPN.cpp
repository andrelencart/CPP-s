#include "../RPN.hpp"

RPN::RPN(){ };

RPN::~RPN(){ };

RPN::RPN(const RPN &copy){
	this->operator=(copy);
}

RPN& RPN::operator=(const RPN &copy){

}

std::string RPN::ParsingInput(std::string input){

	return input;
}

int RPN::CalculateOperators(int n1, int n2, char type){

	switch (type)
	{
		case '+':
			return (n1 + n2);
		case '-':
			return (n1 - n2);
		case '*':
			return (n1 * n2);
		case '/':
			if (n2 == 0) {
				std::cerr << "Error: division by zero" << std::endl;
				exit(1);
			}
			return (n1 / n2);
		default:
			std::cerr << "Error: invalid operator" << std::endl;
			exit(1);
	}
}
