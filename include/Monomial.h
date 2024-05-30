// Monomial.h
#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <vector>

struct Monomial {
    double coefficient;
    std::vector<int> exponents;

    Monomial(double coeff, const std::vector<int>& exps);

    bool operator<(const Monomial& other) const;
    bool operator==(const Monomial& other) const;
};

#endif // MONOMIAL_H