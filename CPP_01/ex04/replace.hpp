#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <fstream>


class Replace {
	
	private:
	std::string in_file;
	std::string s1;
	std::string s2;

	public:
	Replace(std::string infile, std::string find, std::string repl);
	~Replace();

	void replace_strings(std::string &content, std::string &from, std::string &to);
	void process();
};

#endif