// Monomial.h
#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <vector>

struct Monomial {
    double coefficient;
    std::vector<int> exponents;

    Monomial(); // Default constructor: represent a unity coefficient
    Monomial(double coeff, const std::vector<int>& exps); //Constructor

    Monomial operator+(const Monomial& other);
    Monomial operator-(const Monomial& other);
    Monomial operator*(const Monomial& other);
    Monomial operator/(const Monomial& other);

    bool operator==(const Monomial& other);

    void print() const;
};

#endif // MONOMIAL_H