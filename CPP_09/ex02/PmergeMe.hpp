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
		int BinarySearchVectorBound(const std::vector<int>& vec, int value, size_t rightBound);
		int BinarySearchDequeBound(const std::deque<int>& vec, int value, size_t rightBound);
		void SortPairsByARecursiveVector(std::vector<std::pair<int, int> >& pairs);
		void SortPairsByARecursiveDeque(std::deque<std::pair<int, int> >& pairs);
		std::vector<size_t> BuildJacobsthalOrder(size_t pendCount);

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