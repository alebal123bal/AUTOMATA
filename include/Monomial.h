// Monomial.h
#ifndef MONOMIAL_H
#define MONOMIAL_H

#include "MathConstants.h"
#include <vector>

class Monomial {
    public:
        double coefficient;
        std::vector<int> exponents;
    
        Monomial(); // Default constructor: represent a unity coefficient
        Monomial(double coeff, const std::vector<int>& exps); //Constructor

        Monomial operator+(const Monomial& other) const;
        Monomial operator-(const Monomial& other) const;
        Monomial operator*(const Monomial& other) const;
        Monomial operator/(const Monomial& other) const;
        Monomial pow(int exponent) const;

        bool operator==(const Monomial& other);
        bool hasEqualExponents(const Monomial& other) const;
        bool isPureCoefficient() const;
        
        double eval(const std::vector<double>& values) const;

        void print() const;
};

#endif // MONOMIAL_H