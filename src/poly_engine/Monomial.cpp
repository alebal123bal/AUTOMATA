#include "Monomial.h"

Monomial::Monomial() : coefficient(1.0), exponents({}) {}  // Default constructor initializes to unity

Monomial::Monomial(double coeff, const std::vector<int>& exps) : coefficient(coeff), exponents(exps) {}

Monomial Monomial::operator+(const Monomial& other) {
    //TODO: Implement addition logic
    return Monomial(); // Return default Monomial (unity) for now
}

Monomial Monomial::operator-(const Monomial& other) {
    //TODO: Implement subtraction logic
    return Monomial(); // Return default Monomial (unity) for now
}

Monomial Monomial::operator*(const Monomial& other) {
    //TODO: Implement multiplication logic
    return Monomial(); // Return default Monomial (unity) for now
}

Monomial Monomial::operator/(const Monomial& other) {
    //TODO: Implement division logic
    return Monomial(); // Return default Monomial (unity) for now
}