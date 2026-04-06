#pragma once

# include <iostream>
# include <cstdlib>
# include <stack>
# include <cctype>
# include <cstring>
# include <sstream>

class RPN
{
	private:
		std::stack<int> _Stack;
	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
	
	std::string CalculateInput(std::string input);
	bool	CalculateOperators(int n1, int n2, char type, int &out);
};