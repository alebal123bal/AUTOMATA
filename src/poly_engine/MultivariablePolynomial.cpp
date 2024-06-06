// MultivariablePolynomial.cpp
#include "MultivariablePolynomial.h"
#include "GlobalConfig.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>


// Default constructor
MultivariablePolynomial::MultivariablePolynomial() {
    //Do nothing
}

// Parametrized constructor: initialize the vector of monomials
MultivariablePolynomial::MultivariablePolynomial(const std::vector<Monomial>& monomials): monomialVec(monomials) {
    cleanup();
}

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(double coefficient, const std::vector<int>& exponents) {
    monomialVec.push_back(Monomial(coefficient, exponents));
    cleanup();
}

//This is to define the poly one Monomial at a time
void MultivariablePolynomial::addMonomial(const Monomial& mono){
    monomialVec.push_back(mono);
    cleanup();
}


MultivariablePolynomial MultivariablePolynomial::operator+(const MultivariablePolynomial& other) const{
    //Use the Monomial exponents vector as key and the Monomial coefficient as value
    std::map<std::vector<int>, double> expToCoeffMap;

    // Combine monomials from this polynomial
    for (const auto& mono : monomialVec) {
        expToCoeffMap[mono.exponents] += mono.coefficient;
    }

    // Combine monomials from the other polynomial
    for (const auto& mono : other.monomialVec) {
        expToCoeffMap[mono.exponents] += mono.coefficient;
    }

    // Build the resulting polynomial
    MultivariablePolynomial result;
    for (const auto& pair : expToCoeffMap) {
        if (pair.second != 0) {  // Ignore monomials with a coefficient of 0
            result.addMonomial(pair.second, pair.first);
        }
    }

    result.cleanup();
    return result;
}


MultivariablePolynomial MultivariablePolynomial::operator-(const MultivariablePolynomial& other) const{
    //Use the Monomial exponents vector as key and the Monomial coefficient as value
    std::map<std::vector<int>, double> expToCoeffMap;

    // Combine monomials from this polynomial
    for (const auto& mono : monomialVec) {
        expToCoeffMap[mono.exponents] += mono.coefficient;
    }

    // Combine monomials from the other polynomial
    for (const auto& mono : other.monomialVec) {
        expToCoeffMap[mono.exponents] -= mono.coefficient;
    }

    // Build the resulting polynomial
    MultivariablePolynomial result;
    for (const auto& pair : expToCoeffMap) {
        if (pair.second != 0) {  // Ignore monomials with a coefficient of 0
            result.addMonomial(pair.second, pair.first);
        }
    }

    result.cleanup();
    return result;
}

MultivariablePolynomial MultivariablePolynomial::operator*(const MultivariablePolynomial& other) const{
    MultivariablePolynomial result;

    // Iterate over each monomial in the first polynomial
    for (const auto& mono1 : monomialVec) {
        // And each monomial in the second polynomial
        for (const auto& mono2 : other.monomialVec) {
            // Calculate the product of the coefficients
            double newCoefficient = mono1.coefficient * mono2.coefficient;

            // Calculate the new exponents by adding corresponding exponents
            std::vector<int> newExponents;
            newExponents.reserve(mono1.exponents.size());  // Assume sizes are the same and fixed

            // Since the vector sizes are the same, we can sum directly
            for (size_t i = 0; i < mono1.exponents.size(); ++i) {
                newExponents.push_back(mono1.exponents[i] + mono2.exponents[i]);
            }

            // Add the new monomial to the result polynomial
            result.addMonomial(newCoefficient, newExponents);
        }
    }

    // After all products are added, combine like terms
    result.cleanup();
    return result;
}

//https://www.kristakingmath.com/blog/predator-prey-systems-ghtcp-5e2r4-427ab
std::pair<MultivariablePolynomial, MultivariablePolynomial> MultivariablePolynomial::operator/(const MultivariablePolynomial& other) const{
    MultivariablePolynomial result;
    MultivariablePolynomial remainder = *this;
    
    //Get the first monomial used to divide each Monomial in the long division procedure
    const Monomial* first = &monomialVec.back();
    const Monomial* mono1 = &other.monomialVec.back();

    //Itearate each monomial of the Polynomial
    while (!remainder.monomialVec.empty()) {
        //Perform Monomial division on the first Monomial
        Monomial div = *first / *mono1;
        
        //If there is a negative exponent, then you have finished performing division
        bool negExp = false; 
        for (int exp : div.exponents) {
            if (exp < 0) {
                negExp = true;
                break;
            }
        }
        if(negExp){
            return std::pair(result, remainder);  //TODO: add support for remainder too
        }

        //Push it to the result
        result.addMonomial(div);

        //Multiply each dividend's ("other") Monomial by div
        //I need a new Polynomial
        MultivariablePolynomial div_to_poly({div});
        //Perform multiplication
        MultivariablePolynomial prod = other * div_to_poly;
        //Perform difference
        remainder = remainder - prod;
        //Pick last, as they are already ordered by cleanup but I need it backwards.
        first = &remainder.monomialVec.back();
    }

    return std::pair(result, remainder);
}

MultivariablePolynomial MultivariablePolynomial::pow(int exponent) const {
    if (exponent < 0) {
        throw std::invalid_argument("Negative exponent is not supported for MultivariablePolynomials.\
         Use MultivariablePolynomialsFraction instead");
    }
    if (exponent == 0) {
        // Any non-zero number to the power of 0 is 1, we need to define what a "1" is for polynomials.
        MultivariablePolynomial result;
        result.addMonomial(1, std::vector<int>(this->monomialVec[0].exponents.size(), 0)); // Assuming exponents.size() > 0
        return result;
    }
    if (exponent == 1) {
        return *this;
    }

    MultivariablePolynomial result = *this;
    MultivariablePolynomial base = *this;

    // Start the exponentiation by squaring algorithm
    result = MultivariablePolynomial();  // Reset result
    result.addMonomial(1, std::vector<int>(base.monomialVec[0].exponents.size(), 0)); // Identity polynomial

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = result * base;  // Multiply result by base if exponent is odd
        }
        base = base * base;        // Square the base
        exponent /= 2;             // Divide exponent by 2
    }

    return result;
}

std::vector<MultivariablePolynomial> MultivariablePolynomial::factorize_engine() const{
    std::vector<MultivariablePolynomial> factors;

    MultivariablePolynomial factor = generateFactor(1);

    factor.print();

    return factors;
};


bool MultivariablePolynomial::operator==(const MultivariablePolynomial& other){
    // Check if they have the same number of monomials
    if (monomialVec.size() != other.monomialVec.size()) {
        return false;
    }

    // Since the order of monomials doesn't matter, we need to sort them first

    //Define the lambda function for the std::sort algo
    auto monomialSorter = [](const Monomial& a, const Monomial& b) {
        if (a.exponents == b.exponents) {
            return a.coefficient < b.coefficient;
        }
        return a.exponents < b.exponents;
    };

    std::vector<Monomial> sortedMonomials1 = monomialVec;
    std::vector<Monomial> sortedMonomials2 = other.monomialVec;

    std::sort(sortedMonomials1.begin(), sortedMonomials1.end(), monomialSorter);
    std::sort(sortedMonomials2.begin(), sortedMonomials2.end(), monomialSorter);

    // Compare sorted monomials one by one
    for (size_t i = 0; i < sortedMonomials1.size(); ++i) {
        // Use the Monomial's operator== which considers EPSILON for coefficients
        if (!(sortedMonomials1[i] == sortedMonomials2[i])) {
            return false;
        }
    }

    return true;
}


void MultivariablePolynomial::cleanup() {
    if (monomialVec.empty()) return;

    // Sort monomials by their exponents
    
    std::sort(monomialVec.begin(), monomialVec.end(), [](const Monomial& a, const Monomial& b) {
        return a.exponents < b.exponents;
    });

    // Combine like terms and remove small coefficients
    std::vector<Monomial> cleanedVec;
    Monomial current = monomialVec[0];
    
    for (size_t i = 1; i < monomialVec.size(); ++i) {
        if (monomialVec[i].exponents == current.exponents) {
            // Combine coefficients if exponents match
            current.coefficient += monomialVec[i].coefficient;
        } else {
            // Push the previous term if its coefficient is significant
            if (std::fabs(current.coefficient) >= MathConstants::EPSILON) {
                cleanedVec.push_back(current);
            }
            current = monomialVec[i];  // Start a new term
        }
    }

    // Don't forget to add the last processed term if significant
    if (std::fabs(current.coefficient) >= MathConstants::EPSILON) {
        cleanedVec.push_back(current);
    }

    // Replace the original vector with the cleaned version
    monomialVec = std::move(cleanedVec);
}


double MultivariablePolynomial::eval(const std::vector<double>& values) const {
    double result = 0.0;

    // Check if the number of values matches the expected number of variables
    if (!monomialVec.empty() && values.size() != monomialVec[0].exponents.size()) {
        throw std::invalid_argument("Number of values does not match the number of variables in the polynomial.");
    }

    // Iterate over each monomial and use its eval method
    for (const auto& monomial : monomialVec) {
        result += monomial.eval(values);  // Utilize Monomial's eval function
    }

    return result;
}


void MultivariablePolynomial::print() const {
    if (monomialVec.empty()) {
        std::cout << "0";  // Print 0 for an empty polynomial
        return;
    }

    bool first = true;  // Flag to check if it's the first monomial
    for (const auto& monomial : monomialVec) {
        if (!first) {
            std::cout << " + ";  // Add a plus sign before every monomial except the first
        }
        monomial.print();  // Call print on each monomial
        first = false;  // After the first iteration, set first to false
    }
    std::cout << std::endl;  // End with a new line
}


// Function to generate all possible monomials up to the maximum exponents
std::vector<Monomial> MultivariablePolynomial::generateFullMonomialSet() const{
    if (monomialVec.empty()) return {};

    // Step 1: Determine the number of variables and max exponents for each
    size_t numVariables = SYM_NUMBER;
    std::vector<int> maxExponents(numVariables, 0);

    for (const auto& mono : monomialVec) {
        for (size_t i = 0; i < numVariables; ++i) {
            maxExponents[i] = std::max(maxExponents[i], mono.exponents[i]);
        }
    }

    // Step 2: Generate all possible monomials given the max exponents
    std::vector<Monomial> allMonomials;
    std::vector<int> currentExponents(numVariables, 0);

    // Recursive function to generate monomials
    std::function<void(int)> generateMonomials = [&](int varIndex) {
        if (varIndex == numVariables) {
            // Base case: all variables have been assigned an exponent
            allMonomials.push_back(Monomial{1.0, currentExponents});  // Assume coefficient 1
            return;
        }

        // Recursive case: iterate over all possible exponents for the current variable
        for (int exp = 0; exp <= maxExponents[varIndex]; ++exp) {
            currentExponents[varIndex] = exp;
            generateMonomials(varIndex + 1);
        }
        currentExponents[varIndex] = 0;  // Reset before going back up the stack
    };

    generateMonomials(0);  // Start the recursion with the first variable

    return allMonomials;
}

//Find max coefficient of each symbol inside the poly
int MultivariablePolynomial::findMaxCoefficient() const {
    int maxCoeff = 0;
    for (const auto& mono : monomialVec) {
        maxCoeff = std::max(maxCoeff, (int)std::abs(mono.coefficient)); //Round with casting
    }
    return maxCoeff;
}

// Utility to determine if the polynomial is purely a constant
bool MultivariablePolynomial::isPureCoefficientPoly() const {
    return monomialVec.size() == 1 && monomialVec[0].isPureCoefficient();
}

//Look for factors
MultivariablePolynomial MultivariablePolynomial::generateFactor(int step) const {
    std::vector<Monomial> allMonomials = generateFullMonomialSet();
    int maxCoeff = findMaxCoefficient();

    MultivariablePolynomial foundFactor; // Found factor, if any

    std::function<bool(MultivariablePolynomial&, size_t)> tryCombos = [&](MultivariablePolynomial& currentPoly, size_t startIndex) -> bool {
        for (size_t i = startIndex; i < allMonomials.size(); ++i) {
            for (int coeff = -maxCoeff; coeff <= maxCoeff; coeff += step) {
                Monomial newMono = allMonomials[i];
                newMono.coefficient = coeff;
                currentPoly.monomialVec.push_back(newMono);
                currentPoly.cleanup();

                // Perform division and check remainder
                if (currentPoly.isPureCoefficientPoly()){
                    continue;
                }

                auto [quotient, remainder] = *this / currentPoly;
                if (remainder.monomialVec.empty()) {
                    foundFactor = currentPoly;
                    return true; // Exit recursion and loops immediately
                }

                MultivariablePolynomial correct_compare;
                correct_compare.addMonomial(1, {1, 0});
                correct_compare.addMonomial(3, {0, 1});

                if(currentPoly == correct_compare){
                    currentPoly.print();
                    std::cout << std::endl;
                }

                // Recurse with the new monomial added
                if (tryCombos(currentPoly, i + 1)) return true;

                // Backtrack
                currentPoly.monomialVec.pop_back();
            }
        }
        return false;
    };

    // Initialize with pure coefficients first
    for (int coeff = -maxCoeff; coeff <= maxCoeff; coeff += step) {
        if (coeff == 0) continue; // Skip zero as it is trivial and not useful as a factor

        MultivariablePolynomial initial;
        initial.monomialVec.push_back(Monomial{coeff, std::vector<int>(allMonomials.front().exponents.size(), 0)});  // Adding a pure coefficient

        // Don't check if this pure coefficient divides the polynomial

        // Try adding more complex terms to the initial pure coefficient
        if (tryCombos(initial, 0)) break; // Stop if a factor is found
    }

    return foundFactor; // This will be an empty polynomial unless a factor was found
}