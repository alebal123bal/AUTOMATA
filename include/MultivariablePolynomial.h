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
    
    //Polynomial construction and definition functions

    void addMonomial(double coefficient, const std::vector<int>& exponents);
    void addMonomial(const Monomial& mono);

    //Standard operators

    MultivariablePolynomial operator+(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator-(const MultivariablePolynomial& other) const;
    MultivariablePolynomial operator*(const MultivariablePolynomial& other) const;
    std::pair<MultivariablePolynomial, MultivariablePolynomial> operator/(const MultivariablePolynomial& other) const;

    //Custom functions

    MultivariablePolynomial pow(int exponent) const;
    std::vector<MultivariablePolynomial> factorize() const; //Implement Groebner's
    std::vector<MultivariablePolynomial> factorize_engine() const; //Brute force

    //Equality check

    bool operator==(const MultivariablePolynomial& other);
    bool isPureCoefficientPoly() const ;

    //Housekeeping functions

    void cleanup();
    void ordering(int lexicographic_ordering);

    //Numerical evalutation functions

    double eval(const std::vector<double>& values) const;

    //Display functions

    void print() const;

private:
    std::vector<Monomial> generateFullMonomialSet() const;
    int findMaxCoefficient() const;
    MultivariablePolynomial generateFactor(int step) const;
};

#endif // MULTIVARIABLE_POLYNOMIAL_H