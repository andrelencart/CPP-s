#pragma once

# include <iostream>
# include <exception>
# include <climits>
# include <cstdlib>
# include <vector>
# include <deque>

class PmergeMe{
	private:
		std::deque<int> _Dec;
		std::vector<int> _Vec;

		bool IsValideNumber(const std::string &str);
		long IsNumberTooLong(const std::string &str);
		
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		void DisplayOutput(std::string str);
	};