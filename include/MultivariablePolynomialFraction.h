// MultivariablePolynomialFraction.h
#ifndef MULTIVARIABLE_POLYNOMIAL_FRACTION_H
#define MULTIVARIABLE_POLYNOMIAL_FRACTION_H

#include "Monomial.h"
#include <map>
#include <vector>

class MultivariablePolynomialFraction {
private:
    std::map<Monomial, double> num_terms;  // Map monomials to coefficients for unique identification
    std::map<Monomial, double> den_terms;  // Map monomials to coefficients for unique identification

public:
    void num_addMonomial(double coefficient, const std::vector<int>& exponents);
    void den_addMonomial(double coefficient, const std::vector<int>& exponents);
    MultivariablePolynomialFraction operator+(const MultivariablePolynomialFraction& other);
    void print() const;

private:
    void printTerms(const std::map<Monomial, double>& terms) const;
};

#endif // MULTIVARIABLE_POLYNOMIAL_FRACTION_H