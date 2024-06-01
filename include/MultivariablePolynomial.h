// MultivariablePolynomial.h
#ifndef MULTIVARIABLE_POLYNOMIAL
#define MULTIVARIABLE_POLYNOMIAL

#include "Monomial.h"
#include <map>
#include <vector>

class MultivariablePolynomial {
private:
    std::vector<Monomial> monomialVec;

public:
    MultivariablePolynomial();  // Default constructor
    MultivariablePolynomial(const std::vector<Monomial>& monomials);  // Parametrized constructor
    
    void addMonomial(double coefficient, const std::vector<int>& exponents);
    MultivariablePolynomial operator+(const MultivariablePolynomial& other);
    MultivariablePolynomial operator-(const MultivariablePolynomial& other);
    MultivariablePolynomial operator*(const MultivariablePolynomial& other);
    MultivariablePolynomial operator/(const MultivariablePolynomial& other);
    MultivariablePolynomial pow(int exponent) const;

    void print() const;

};

#endif // MULTIVARIABLE_POLYNOMIAL_H