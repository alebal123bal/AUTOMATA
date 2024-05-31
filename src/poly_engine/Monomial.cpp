#include "Monomial.h"
#include <iostream>

Monomial::Monomial() : coefficient(1.0), exponents({}) {}  // Default constructor initializes to unity

Monomial::Monomial(double coeff, const std::vector<int>& exps) : coefficient(coeff), exponents(exps) {}

Monomial Monomial::operator+(const Monomial& other) {
    // Check if the exponents are the same
    if (this->exponents == other.exponents) {
        // If exponents match, add the coefficients
        return Monomial(this->coefficient + other.coefficient, this->exponents);
    } else {
        // Exponents do not match, return an error state (or handle differently if needed)
        std::cerr << "Error: Attempted to add monomials with different terms." << std::endl;
        return Monomial(0, {});  // Represents an invalid monomial state
    }
}

Monomial Monomial::operator-(const Monomial& other) {
    // Check if the exponents are the same
    if (this->exponents == other.exponents) {
        // If exponents match, add the coefficients
        return Monomial(this->coefficient - other.coefficient, this->exponents);
    } else {
        // Exponents do not match, return an error state (or handle differently if needed)
        std::cerr << "Error: Attempted to add monomials with different terms." << std::endl;
        return Monomial(0, {});  // Represents an invalid monomial state
    }
}

Monomial Monomial::operator*(const Monomial& other) {
    //TODO: Implement multiplication logic
    return Monomial(); // Return default Monomial (unity) for now
}

Monomial Monomial::operator/(const Monomial& other) {
    //TODO: Implement division logic
    return Monomial(); // Return default Monomial (unity) for now
}