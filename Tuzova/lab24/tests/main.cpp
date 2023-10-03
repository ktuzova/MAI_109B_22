#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

#include "../include/expression.hpp"
#include "../include/splitter.hpp"

int main() {
    std::cout << "Введите выражение по типу 40 * a * b * c * v + 10 * a * b * c + 20 * d * c * b * v";
    std::string expression;
    std::getline(std::cin, expression);
    Expression e1;
    Splitter s1;
    std::vector<std::string> terms = s1.splitTerms(expression);
    if (terms.empty()) {
        std::cout << "No terms found in the expression." << std::endl;
        return 0;
    }
    
    std::unordered_map<std::string, int> commonFactors;
    std::vector<int> numbers; // For storing numbers in the expression
 
    e1.processTerms(terms, commonFactors, numbers);
    
    // Output common factors
    e1.outputCommonFactors(commonFactors);

    // Find and output the GCD of numbers
    Expression e2;
    int gcd = e2.findGCD(numbers);
    if (gcd > 1) {
        std::cout << " * " << gcd;
    }
    std::cout << std::endl;
    return 0;
}
