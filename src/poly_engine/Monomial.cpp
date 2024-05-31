#include "Monomial.h"
#include <iostream>

Monomial::Monomial() : coefficient(1.0), exponents({}) {}  // Default constructor initializes to unity

Monomial::Monomial(double coeff, const std::vector<int>& exps) : coefficient(coeff), exponents(exps) {}

//These operators can only return another Monomial, i.e. trying to add monomials with different terms, that
//would create a Polynomial, will fail.
//Same goes for division, as a division with a "bigger" Monomial would lead to a fractional Monomial.

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
    // Multiply the coefficients
    double newCoefficient = this->coefficient * other.coefficient;

    // Add the exponents; vectors are of the same length
    std::vector<int> newExponents(this->exponents.size(), 0);

    for (size_t i = 0; i < this->exponents.size(); ++i) {
        newExponents[i] = this->exponents[i] + other.exponents[i];  // Directly add corresponding exponents
    }

    return Monomial(newCoefficient, newExponents);
}

Monomial Monomial::operator/(const Monomial& other) {
    //Implement division logic: only if this Monomial exponent element is bigger you can subtract; otherwise
    //return an error, as it would get a negative exponent, i.e. a fractional Monomial

    // Divide the coefficients
    double newCoefficient = this->coefficient / other.coefficient;

    // Sub the exponents; vectors are of the same length
    std::vector<int> newExponents(this->exponents.size(), 0);

    for (size_t i = 0; i < this->exponents.size(); ++i) {
        if (this->exponents[i] >= other.exponents[i]){
            newExponents[i] = this->exponents[i] - other.exponents[i];  // Sub corresponding exponents
        }
        else{
            std::cerr << "Error: Attempted to divide monomials with a bigger one." << std::endl;
            return Monomial(0, {});  // Represents an invalid monomial state
        }
    }

    return Monomial(newCoefficient, newExponents);
    return Monomial(); // Return default Monomial (unity) for now
}

bool Monomial::operator==(const Monomial& other){
    return (this->coefficient == other.coefficient) && (this->exponents == other.exponents);
};