// MultivariablePolynomial.cpp
#include "MultivariablePolynomial.h"
#include <iostream>
#include <cmath> // For fabs
#include <algorithm>
#include <map>


// Default constructor
MultivariablePolynomial::MultivariablePolynomial() {
    //Do nothing
}

// Parametrized constructor
MultivariablePolynomial::MultivariablePolynomial(const std::vector<Monomial>& monomials)
    : monomialVec(monomials) {}  // Initialize the vector of monomials

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(double coefficient, const std::vector<int>& exponents) {
    monomialVec.push_back(Monomial(coefficient, exponents));
}


MultivariablePolynomial MultivariablePolynomial::operator+(const MultivariablePolynomial& other) {
    //Use the Monomial exponents vector as key and the Monomial coefficient as value
    std::map<std::vector<int>, double> expToCoeffMap;

    // Combine monomials from this polynomial
    for (const auto& mono : monomialVec) {
        expToCoeffMap[mono.exponents] += mono.coefficient;
    }

    // Combine monomials from the other polynomial
    for (const auto& mono : other.monomialVec) {
        expToCoeffMap[mono.exponents] += mono.coefficient;
    }

    // Build the resulting polynomial
    MultivariablePolynomial result;
    for (const auto& pair : expToCoeffMap) {
        if (pair.second != 0) {  // Ignore monomials with a coefficient of 0
            result.addMonomial(pair.second, pair.first);
        }
    }

    return result;
}


MultivariablePolynomial MultivariablePolynomial::operator-(const MultivariablePolynomial& other) {
    MultivariablePolynomial result;
    //TODO
    return result;
}

MultivariablePolynomial MultivariablePolynomial::operator*(const MultivariablePolynomial& other) {
    MultivariablePolynomial result;
    //TODO
    return result;
}

MultivariablePolynomial MultivariablePolynomial::operator/(const MultivariablePolynomial& other) {
    MultivariablePolynomial result;
    //TODO
    return result;
}

MultivariablePolynomial MultivariablePolynomial::pow(int exponent) const{
    MultivariablePolynomial result;
    //TODO
    return result;
}


bool MultivariablePolynomial::operator==(const MultivariablePolynomial& other){
    return false;
}


void MultivariablePolynomial::print() const {
    if (monomialVec.empty()) {
        std::cout << "0";  // Print 0 for an empty polynomial
        return;
    }

    bool first = true;  // Flag to check if it's the first monomial
    for (const auto& monomial : monomialVec) {
        if (!first) {
            std::cout << " + ";  // Add a plus sign before every monomial except the first
        }
        monomial.print();  // Call print on each monomial
        first = false;  // After the first iteration, set first to false
    }
    std::cout << std::endl;  // End with a new line
}
