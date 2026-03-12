#pragma once

# include <iostream>
# include <iomanip>
# include <exception>
# include <climits>
# include <sys/time.h>
# include <cstdlib>
# include <vector>
# include <deque>
# include <algorithm>

class PmergeMe{
	private:
		std::deque<int> _Deq;
		std::vector<int> _Vec;
		double _VecTime;
		double _DeqTime;

		bool IsValideNumber(const std::string &str);
		long IsNumberTooLong(const std::string &str);
		int BinarySearchVector(const std::vector<int>& vec, int value, int left, int right);
		int BinarySearchDeque(const std::deque<int>& deq, int value, int left, int right);
		
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		void DisplayOutput(std::string str);
		void SortVector();
		void SortDeque();
		void DisplayTime();
	};