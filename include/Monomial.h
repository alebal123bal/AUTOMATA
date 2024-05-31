// Monomial.h
#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <vector>

struct Monomial {
    double coefficient;
    std::vector<int> exponents;

    Monomial(); // Default constructor
    Monomial(double coeff, const std::vector<int>& exps);

    Monomial operator+(const Monomial& other);
    Monomial operator-(const Monomial& other);
    Monomial operator*(const Monomial& other);
    Monomial operator/(const Monomial& other);
};

#endif // MONOMIAL_H