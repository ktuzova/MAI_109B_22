#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cstdlib> 

#include "../include/expression.hpp"

// Function to find the greatest common divisor (GCD) of two numbers
int Expression::findGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return findGCD(b, a % b);
}

// Function to find the GCD of a vector of numbers
int Expression::findGCD(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0;
    }
    int gcd = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        gcd = Expression::findGCD(gcd, numbers[i]);
    }
    return gcd;
}
// Функция для обработки терма
void Expression::processTerm(const std::string& term, std::unordered_map<std::string, int>& commonFactors, std::vector<int>& numbers) {
    Splitter s1;
    std::vector<std::string> factors = s1.splitFactors(term);
    for (const std::string& factor : factors) {
        size_t pos = factor.find('*');
        std::string factorWithoutCoefficient = (pos == std::string::npos) ? factor : factor.substr(pos + 1);
        if (isdigit(factorWithoutCoefficient[0])) {
            numbers.push_back(std::atoi(factorWithoutCoefficient.c_str()));
        } else {
            commonFactors[factorWithoutCoefficient] = 1;
        }
    }
}
// Функция для обработки всех термов в выражении
void Expression::processTerms(const std::vector<std::string>& terms, std::unordered_map<std::string, int>& commonFactors, std::vector<int>& numbers) {
    Splitter s1;
    for (size_t i = 0; i < terms.size(); ++i) {
        if (i == 0) {
            // Process the first term
            processTerm(terms[i], commonFactors, numbers);
        } else {
            // Process the rest of the terms
            std::unordered_map<std::string, int> newCommonFactors;
            std::vector<std::string> factors = s1.splitFactors(terms[i]);
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
    }
}

// Функция для вывода общих множителей
void Expression::outputCommonFactors(const std::unordered_map<std::string, int>& commonFactors) {
    bool firstFactor = true;
    for (const auto& factor : commonFactors) {
        if (!firstFactor) {
            std::cout << " * ";
        }
        std::cout << factor.first;
        firstFactor = false;
    }
}

