#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib> 

#include "splitter.hpp"

class Expression{
public:
	// Function to find the greatest common divisor (GCD) of two numbers
	int findGCD(int a, int b);
	// Function to find the GCD of a vector of numbers
	int findGCD(const std::vector<int>& numbers) ;

	void processTerm(const std::string& term, std::unordered_map<std::string, int>& commonFactors, std::vector<int>& numbers);
	void processTerms(const std::vector<std::string>& terms, std::unordered_map<std::string, int>& commonFactors, std::vector<int>& numbers);
	void outputCommonFactors(const std::unordered_map<std::string, int>& commonFactors);
};
#include "../src/expression.cpp"

#endif
