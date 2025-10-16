#include "../replace.hpp"

Replace::Replace(std::string infile, std::string find, std::string repl) 
: in_file(infile), s1(find), s2(repl){

}

Replace::~Replace(){
	
}

void	Replace::process(){
	if (s1.empty()){
		std::cout << "Search Stream cant be EMPTY!!";
		return ;
	}
	
	std::ifstream in(in_file.c_str(), std::ios::in | std::ios::binary);
	if (!in){
		std::cout << "Error Input File: " << in_file << std::endl;
		return ;
	}

	std::string content;
	content.assign(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>());
	in.close();

	replace_strings(content, s1, s2);


	std::string out_file = in_file + ".replace";
	std::ofstream out(out_file.c_str(), std::ios::binary | std::ios::trunc);
	if (!out){
		std::cout << "Error Output File: " << out_file << std::endl;
		return ;
	}
	out << content;
	out.close();
}

void	Replace::replace_strings(std::string &content, std::string &from, std::string &to){
	if (!from.empty()){
		size_t pos = 0;
		while ((pos = content.find(from, pos)) != std::string::npos){
			content.erase(pos, from.length());
			content.insert(pos, to);
			pos += to.length();
		}
	}
}