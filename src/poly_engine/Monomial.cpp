#include "Monomial.h"
#include "GlobalConfig.h"
#include <iostream>
#include <algorithm>
#include <cmath>

// Implementation of the default Monomial constructor
Monomial::Monomial() : coefficient(1.0), exponents(std::vector<int>(SYM_NUMBER, 0)) {
    // The exponents vector is initialized with SYM_NUMBER elements, all set to 0
}

// Implementation of the Monomial constructor
Monomial::Monomial(double coeff, const std::vector<int>& exps) : coefficient(coeff), exponents(exps) {
    // Initialize Monomial with passed coefficient and exponents vector
}

//These operators can only return another Monomial, i.e. trying to add monomials with different terms, that
//would create a Polynomial, will fail.
//Same goes for division, as a division with a "bigger" Monomial would lead to a fractional Monomial.

Monomial Monomial::operator+(const Monomial& other) const{
    // Check if the exponents are the same
    if (this->exponents == other.exponents) {
        // If exponents match, add the coefficients
        return Monomial(this->coefficient + other.coefficient, this->exponents);
    } else {
        // Exponents do not match, return an error state
        throw std::invalid_argument("Error: Attempted to add monomials with different terms.");
    }
}

Monomial Monomial::operator-(const Monomial& other) const{
    // Check if the exponents are the same
    if (this->exponents == other.exponents) {
        // If exponents match, add the coefficients
        return Monomial(this->coefficient - other.coefficient, this->exponents);
    } else {
        // Exponents do not match, return an error state
        throw std::invalid_argument("Error: Attempted to add monomials with different terms.");
    }
}

Monomial Monomial::operator*(const Monomial& other) const{
    // Multiply the coefficients
    double newCoefficient = this->coefficient * other.coefficient;

    // Add the exponents; vectors must have the same length
    std::vector<int> newExponents(this->exponents.size(), 0);

    // Check if mulitplicand and multiplicator have the same length vector
    if(this->exponents.size() != other.exponents.size()){ 
        // Exponent vectors do not match in size, return an error state
        throw std::invalid_argument("Error: exponent vectors do not match in size");
    }

    for (size_t i = 0; i < this->exponents.size(); ++i) {
        newExponents[i] = this->exponents[i] + other.exponents[i];  // Directly add corresponding exponents
    }

    return Monomial(newCoefficient, newExponents);
}

Monomial Monomial::operator*(double scalar) const {
    return Monomial(coefficient * scalar, exponents);
}

Monomial operator*(double scalar, const Monomial& monomial) {
    return monomial * scalar;  // Utilize the member function for multiplication
}

Monomial Monomial::operator/(const Monomial& other) const{
    //Implement division logic

    // Divide the coefficients
    double newCoefficient = this->coefficient / other.coefficient;

    // Sub the exponents; vectors are of the same length
    std::vector<int> newExponents(this->exponents.size(), 0);

    for (size_t i = 0; i < this->exponents.size(); ++i) {
        newExponents[i] = this->exponents[i] - other.exponents[i];  // Directly sub corresponding exponents
    }

    return Monomial(newCoefficient, newExponents);
}

Monomial Monomial::pow(int exponent) const {
    //Accept also negative exponents
    double newCoefficient = std::pow(coefficient, exponent);
    std::vector<int> newExponents;
    
    for (int exp : exponents) {
        newExponents.push_back(exp * exponent); // Multiply each exponent by the power
    }
    
    return Monomial(newCoefficient, newExponents);
}


bool Monomial::operator==(const Monomial& other){
    return std::fabs(this->coefficient - other.coefficient) < MathConstants::EPSILON && this->exponents == other.exponents;
}


bool Monomial::hasEqualExponents(const Monomial& other) const {
    return this->exponents == other.exponents;
}

// A utility function to check if a monomial is a pure coefficient (no variables)
bool Monomial::isPureCoefficient() const {
    return std::all_of(exponents.begin(), exponents.end(), [](int exp){ return exp == 0; });
}

double Monomial::eval(const std::vector<double>& values) const {
    double result = coefficient; // Start with the coefficient
    for (size_t i = 0; i < exponents.size(); ++i) {
        if (i < values.size()) {
            result *= std::pow(values[i], exponents[i]); // Multiply by each variable raised to its exponent
        } else {
            // Handle case where there are more exponents than values provided
            throw std::invalid_argument("Insufficient values provided for the number of variables in Monomial.");
        }
    }
    return result;
}


void Monomial::print() const {
    std::cout << coefficient;

    for (size_t i = 0; i < exponents.size(); ++i) {
        if (exponents[i] != 0) {
            std::cout << " * ";

            // Print the variable: a for 0, b for 1, ..., z for 25
            char variable = 'a' + i;
            std::cout << variable;
            if (exponents[i] != 1) { // Only print exponent if it's not 1
                std::cout << "^" << exponents[i];
            }
        }
    }
}