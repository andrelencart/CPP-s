#include "../RPN.hpp"

RPN::RPN(){ };

RPN::~RPN(){ };

RPN::RPN(const RPN &copy){
	this->operator=(copy);
}

RPN& RPN::operator=(const RPN &copy){
	if (this != &copy){
		_Stack = copy._Stack;
	}
	return *this;
}

std::string RPN::CalculateInput(std::string input){
	std::istringstream in(input);
	std::string token;

	while (in >> token){
		if (token.length() == 1){
			if (std::isdigit(static_cast<unsigned char>(token[0]))){
				int number = token[0] - '0';
				_Stack.push(number);
			}
			else if (std::strchr("*+-/", token[0])){
				if (_Stack.size() < 2)
					return "Error";
				int n2 = _Stack.top(); _Stack.pop();
				int n1 = _Stack.top(); _Stack.pop();
				int result;
				if (!CalculateOperators(n1, n2, token[0], result)){
					if (token[0] == '/')
						return "Error: division by zero";
					return "Error";
				}
				_Stack.push(result);
			}
			else
				return "Error";
		}
		else
			return "Error";
	}
	if (_Stack.size() != 1){
		return "Error";
	}
	int res = _Stack.top();
	std::ostringstream oss;
	oss << res;
	return oss.str();
}

bool RPN::CalculateOperators(int n1, int n2, char type, int &out){

	switch (type)
	{
		case '+':
			out = n1 + n2;
			return true;
		case '-':
			out = n1 - n2;
			return true;
		case '*':
			out = n1 * n2;
			return true;
		case '/':
			if (n2 == 0){
				return false;
			}
			out = n1 / n2;
			return true;
		default:
			return false;
	}
}
