#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib> // For std::atoi

#include "../include/expresion.hpp"

// Function to split the expression into terms
std::vector<std::string> splitTerms(const std::string& expression) {
    std::vector<std::string> terms;
    std::stringstream ss(expression);
    std::string term;
    while (std::getline(ss, term, '+')) {
        terms.push_back(term);
    }
    return terms;
}

// Function to split a term into factors
std::vector<std::string> splitFactors(const std::string& term) {
    std::vector<std::string> factors;
    std::stringstream ss(term);
    std::string factor;
    while (ss >> factor) {
        factors.push_back(factor);
    }
    return factors;
}

// Function to find the greatest common divisor (GCD) of two numbers
int findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

// Function to find the GCD of a vector of numbers
int findGCD(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    int gcd = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        gcd = findGCD(gcd, numbers[i]);
    }
    return gcd;
}


