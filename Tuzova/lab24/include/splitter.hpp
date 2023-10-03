#ifndef SPLITTER_HPP_INCLUDED
#define SPLITTER_HPP_INCLUDED



#include <vector>
#include <string>
#include <sstream>

class Splitter{ 
public:
	
	std::vector<std::string> splitTerms(const std::string& expression);
	
	std::vector<std::string> splitFactors(const std::string& term);
};
#include "../src/splitter.cpp"

#endif
