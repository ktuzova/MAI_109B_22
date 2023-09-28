#ifndef EXPRESSION_HPP_INCLUDED
#define EXPRESSION_HPP_INCLUDED


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib> // For std::atoi



// Function to split the expression into terms
std::vector<std::string> splitTerms(const std::string& expression) 

// Function to split a term into factors
std::vector<std::string> splitFactors(const std::string& term)

// Function to find the greatest common divisor (GCD) of two numbers
int findGCD(int a, int b)
// Function to find the GCD of a vector of numbers
int findGCD(const std::vector<int>& numbers) 

#include "../src/expression.cpp"

#endif
