// MultivariablePolynomial.cpp
#include "MultivariablePolynomial.h"
#include <iostream>
#include <cmath> // For fabs
#include <algorithm>

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(double coefficient, const std::vector<int>& exponents) {
    //TODO
    return;
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
void MultivariablePolynomial::print() const {
    printTerms(terms);
}

void MultivariablePolynomial::printTerms(const std::map<Monomial, double>& terms) const {
    return;
    //TODO
}