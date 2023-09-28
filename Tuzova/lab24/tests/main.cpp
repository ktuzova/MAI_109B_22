#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib> // For std::atoi

#include "../include/expression.hpp"


int main() {
    
    //std::string expression = "40 * a * b * c * v + 10 * a * b * c + 20 * d * c * b * v";
    std::cout << "Введите выражение по типу 40 * a * b * c * v + 10 * a * b * c + 20 * d * c * b * v";
    std::string expression;
    std::getline(std::cin, expression);
    std::vector<std::string> terms = splitTerms(expression);
    if (terms.empty()) {
        std::cout << "No terms found in the expression." << std::endl;
        return 0;
    }
    std::unordered_map<std::string, int> commonFactors;
    std::vector<int> numbers; // For storing numbers in the expression

    // Process the first term
    std::vector<std::string> firstFactors = splitFactors(terms[0]);
    for (const std::string& factor : firstFactors) {
        size_t pos = factor.find('*');
        std::string factorWithoutCoefficient = (pos == std::string::npos) ? factor : factor.substr(pos + 1);
        if (isdigit(factorWithoutCoefficient[0])) {
            numbers.push_back(std::atoi(factorWithoutCoefficient.c_str()));
        } else {
            commonFactors[factorWithoutCoefficient] = 1;
        }
    }

    // Process the rest of the terms
    for (size_t i = 1; i < terms.size(); ++i) {
        std::unordered_map<std::string, int> newCommonFactors;
        std::vector<std::string> factors = splitFactors(terms[i]);
        for (const std::string& factor : factors) {
            size_t pos = factor.find('*');
            std::string factorWithoutCoefficient = (pos == std::string::npos) ? factor : factor.substr(pos + 1);
            if (isdigit(factorWithoutCoefficient[0])) {
                numbers.push_back(std::atoi(factorWithoutCoefficient.c_str()));
            } else if (commonFactors.find(factorWithoutCoefficient) != commonFactors.end()) {
                newCommonFactors[factorWithoutCoefficient] = 1;
            }
        }
        commonFactors = newCommonFactors;
    }

    // Output common factors
    bool firstFactor = true;
    for (const auto& factor : commonFactors) {
        if (!firstFactor) {
            std::cout << " * ";
        }
        std::cout << factor.first;
        firstFactor = false;
    }

    // Find and output the GCD of numbers
    int gcd = findGCD(numbers);
    if (gcd > 1) {
        std::cout << " * " << gcd;
    }

    std::cout << std::endl;
    return 0;
}
