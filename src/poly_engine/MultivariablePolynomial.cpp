// MultivariablePolynomial.cpp
#include "MultivariablePolynomial.h"
#include <iostream>
#include <cmath> // For fabs
#include <algorithm>

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(double coefficient, const std::vector<int>& exponents) {
    Monomial m(coefficient, exponents);
    terms[m] += coefficient;
    if (fabs(terms[m]) < 0.00001) {
        terms.erase(m);
    }
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