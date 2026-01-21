#include "../RPN.hpp"

RPN::RPN(){ };

RPN::~RPN(){ };

RPN::RPN(const RPN &copy){
	this->operator=(copy);
}

RPN& RPN::operator=(const RPN &copy){
	(void)copy;
	return *this;
}

std::string RPN::CalculateInput(std::string input){
	std::istringstream in(input);
	std::string token;

	while (in >> token){
		if (token.length() == 1){
			if (isdigit(token[0])){
				int number = token[0] - '0';
				num.push(number);
			}
			else if (strchr("*+-/", token[0])){
				int n2 = num.top();
				num.pop();
				int n1 = num.top(); 
				num.pop();
				int result = CalculateOperators(n1, n2, token[0]);
				num.push(result);
			}
			else
				continue;
		}
		else
			return "Error\n";
	}
	if (num.size() != 1){
		return "Error\n";
	}
	int res = num.top();

	std::ostringstream oss;
	oss << res;
	return oss.str();
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
