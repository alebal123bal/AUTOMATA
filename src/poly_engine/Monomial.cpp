// Monomial.cpp
#include "Monomial.h"
#include <algorithm> // Include if using any algorithm functions

Monomial::Monomial(double coeff, const std::vector<int>& exps) : coefficient(coeff), exponents(exps) {}

bool Monomial::operator<(const Monomial& other) const {
    if (exponents.size() != other.exponents.size()) {
        return exponents.size() < other.exponents.size();
    }
    return exponents < other.exponents;
}

bool Monomial::operator==(const Monomial& other) const {
    return (coefficient == other.coefficient) && (exponents == other.exponents);
}