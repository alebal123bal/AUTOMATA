// MultivariablePolynomial.h
#ifndef MULTIVARIABLE_POLYNOMIAL
#define MULTIVARIABLE_POLYNOMIAL

#include "Monomial.h"
#include "MathConstants.h"
#include <map>
#include <vector>
#include <algorithm>

class MultivariablePolynomial {
public:
    std::vector<Monomial> monomialVec;

    //Polynomial class constructors

    MultivariablePolynomial();  // Default constructor initialized empty
    MultivariablePolynomial(const std::vector<Monomial>& monomials);  // Parametrized constructor
    // TODO: add copy constructor
    
    //Polynomial construction and definition functions

    void addMonomial(double coefficient, const std::vector<int>& exponents);
    void addMonomial(const Monomial& mono);

    //Standard operators

    MultivariablePolynomial operator+(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator-(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator*(const MultivariablePolynomial& other) const;
    std::pair<MultivariablePolynomial, MultivariablePolynomial> operator/(const MultivariablePolynomial& other) const;

    //TODO: add scalar * and / operators too

    //Custom functions

    MultivariablePolynomial pow(int exponent) const;

    //Equality check

    bool operator==(const MultivariablePolynomial& other);
    bool isPureCoefficientPoly() const ;

    //Housekeeping functions

    void cleanup();

    //Numerical evalutation functions

    double eval(const std::vector<double>& values) const;

    //Display functions

    void print() const;

private:
    int findMaxCoefficient() const;
};

#endif // MULTIVARIABLE_POLYNOMIAL_H