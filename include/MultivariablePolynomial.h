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

    //TODO: add scalar * and / operators too

    //Custom functions

    MultivariablePolynomial pow(int exponent) const;

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
    MultivariablePolynomial generateFactor(int max_iter, int step) const;
    template<typename T>
    std::vector<std::vector<T>> generateNElementSubsets(const std::vector<T>& elements, size_t n);
};

#endif // MULTIVARIABLE_POLYNOMIAL_H