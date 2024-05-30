// MultivariablePolynomial.h
#ifndef MULTIVARIABLE_POLYNOMIAL
#define MULTIVARIABLE_POLYNOMIAL

#include "Monomial.h"
#include <map>
#include <vector>

class MultivariablePolynomial {
private:
    std::map<Monomial, double> terms;

public:
    void addMonomial(double coefficient, const std::vector<int>& exponents);
    MultivariablePolynomial operator+(const MultivariablePolynomial& other);
    MultivariablePolynomial operator-(const MultivariablePolynomial& other);
    MultivariablePolynomial operator*(const MultivariablePolynomial& other);
    MultivariablePolynomial operator/(const MultivariablePolynomial& other);
    void print() const;

private:
    void printTerms(const std::map<Monomial, double>& terms) const;
};

#endif // MULTIVARIABLE_POLYNOMIAL_H