// MultivariablePolynomial.cpp
#include "MultivariablePolynomial.h"
#include <iostream>
#include <cmath> // For fabs
#include <algorithm>


// Default constructor
MultivariablePolynomial::MultivariablePolynomial() {
    // Add a default Monomial unity (1.0 as coefficient and empty exponents vector)
    monomialVec.push_back(Monomial(1.0, std::vector<int>{}));
}

// Parametrized constructor
MultivariablePolynomial::MultivariablePolynomial(const std::vector<Monomial>& monomials)
    : monomialVec(monomials) {}  // Initialize the vector of monomials

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(double coefficient, const std::vector<int>& exponents) {
    monomialVec.push_back(Monomial(coefficient, exponents));
}

MultivariablePolynomial MultivariablePolynomial::operator+(const MultivariablePolynomial& other) {
    MultivariablePolynomial result;
    //TODO
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

void MultivariablePolynomial::print() const {
    return;
}
