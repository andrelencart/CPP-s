#pragma once

# include <iostream>
# include <vector>
# include <deque>

class PmergeMe{
	private:
		std::deque<int> _Dec;
		std::vector<int> _Vec;
	
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();
};