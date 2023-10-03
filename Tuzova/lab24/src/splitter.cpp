
#include <vector>
#include <string>
#include <sstream>

#include "../include/splitter.hpp"

// Function to split the expression into terms
std::vector<std::string> Splitter::splitTerms(const std::string& expression) {
    std::vector<std::string> terms;
    std::stringstream ss(expression);
    std::string term;
    while (std::getline(ss, term, '+')) {
        terms.push_back(term);
    }
    return terms;
}

// Function to split a term into factors
std::vector<std::string> Splitter::splitFactors(const std::string& term) {
    std::vector<std::string> factors;
    std::stringstream ss(term);
    std::string factor;
    while (ss >> factor) {
        factors.push_back(factor);
    }
    return factors;
}


