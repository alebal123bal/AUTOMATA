// MultivariablePolynomialFraction.cpp
#include "MultivariablePolynomialFraction.h"
#include <iostream>
#include <cmath> // For fabs
#include <algorithm>

void MultivariablePolynomialFraction::num_addMonomial(double coefficient, const std::vector<int>& exponents) {
    Monomial m(coefficient, exponents);
    num_terms[m] += coefficient;
    if (fabs(num_terms[m]) < 0.00001) {
        num_terms.erase(m);
    }
}

void MultivariablePolynomialFraction::den_addMonomial(double coefficient, const std::vector<int>& exponents) {
    Monomial m(coefficient, exponents);
    den_terms[m] += coefficient;
    if (fabs(den_terms[m]) < 0.00001) {
        den_terms.erase(m);
    }
}

MultivariablePolynomialFraction MultivariablePolynomialFraction::operator+(const MultivariablePolynomialFraction& other) {
    MultivariablePolynomialFraction result;
    if (this->den_terms == other.den_terms) {
        for (auto& term : this->num_terms) {
            result.num_addMonomial(term.second, term.first.exponents);
        }
        for (auto& term : other.num_terms) {
            result.num_addMonomial(term.second, term.first.exponents);
        }
        result.den_terms = this->den_terms; // Copy any denominator since they are the same
    } else {
        // More complex addition logic for different denominators
        // This is a placeholder for actual LCM handling
        std::cout << "Different denominators - LCM handling not implemented." << std::endl;
        // Implement logic here to handle LCM
    }
    return result;
}

void MultivariablePolynomialFraction::print() const {
    printTerms(num_terms);
    if (!(den_terms.size() == 1 && den_terms.begin()->first.exponents.empty() && fabs(den_terms.begin()->second - 1.0) < 0.00001)) {
        std::cout << " / ";
        printTerms(den_terms);
    }
}

void MultivariablePolynomialFraction::printTerms(const std::map<Monomial, double>& terms) const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }
    bool first = true;
    static const char* var_names[] = {"x", "y", "z"}; // Extend this as needed
    for (const auto& pair : terms) {
        if (!first) {
            std::cout << " + ";
        }
        first = false;

        std::cout << pair.second;
        bool firstVar = true;
        for (size_t i = 0; i < pair.first.exponents.size(); ++i) {
            if (pair.first.exponents[i] != 0) {
                if (!firstVar) {
                    std::cout << " * ";
                }
                std::cout << var_names[i] << "^" << pair.first.exponents[i];
                firstVar = false;
            }
        }
    }
}

std::vector<int> MultivariablePolynomialFraction::max_exponents(const std::vector<int>& a, const std::vector<int>& b) const {
    std::vector<int> result(std::max(a.size(), b.size()), 0);
    for (size_t i = 0; i < result.size(); ++i) {
        int exp_a = i < a.size() ? a[i] : 0;
        int exp_b = i < b.size() ? b[i] : 0;
        result[i] = std::max(exp_a, exp_b);
    }
    return result;
}