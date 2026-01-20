#pragma once

# include <iostream>
# include <cstdlib>
# include <stack>

class RPN
{
	private:
		std::stack<int> num;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
	
	std::string ParsingInput(std::string input);
	int		CalculateOperators(int n1, int n2, char type);
};