// MultivariablePolynomial.h
#ifndef MULTIVARIABLE_POLYNOMIAL
#define MULTIVARIABLE_POLYNOMIAL

#include "Monomial.h"
#include "MathConstants.h"
#include <map>
#include <vector>
#include <algorithm>

class MultivariablePolynomial {
private:

public:
    std::vector<Monomial> monomialVec;

    MultivariablePolynomial();  // Default constructor initialized empty
    MultivariablePolynomial(const std::vector<Monomial>& monomials);  // Parametrized constructor
    
    void addMonomial(double coefficient, const std::vector<int>& exponents);
    void addMonomial(const Monomial& mono);
    MultivariablePolynomial operator+(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator-(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator*(const MultivariablePolynomial& other) const;
    std::pair<MultivariablePolynomial, MultivariablePolynomial> operator/(const MultivariablePolynomial& other) const;
    MultivariablePolynomial pow(int exponent) const;

    bool operator==(const MultivariablePolynomial& other);

    void cleanup();

    double eval(const std::vector<double>& values) const;

    void print() const;

};

#endif // MULTIVARIABLE_POLYNOMIAL_H