#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Monomial.h"
#include "MultivariablePolynomial.h"
#include "MultivariablePolynomialFraction.h"

extern bool testAddition();
extern bool testSubtraction();
extern bool testMultiplication();
extern bool testDivision();
extern bool testPow();

extern bool testPolynomialAddition();
extern bool testPolynomialSubtraction();
extern bool testPolynomialMultiplication();
extern bool testPolynomialDivision();
extern bool testPolynomialDivisionBig();
extern bool testPolynomialMultiplyDivide();
extern bool testRemainderDivision();
extern bool testPolynomialPower();

int main() {
    bool additionPassed = testAddition();
    bool subtractionPassed = testSubtraction();
    bool multiplicationPassed = testMultiplication();
    bool divisionPassed = testDivision();
    bool powerPassed = testPow();

    // Return non-zero if any tests fail
    bool Monomial_tests_passed = additionPassed && subtractionPassed && multiplicationPassed && divisionPassed && powerPassed;
    
    additionPassed = testPolynomialAddition();
    subtractionPassed = testPolynomialSubtraction();
    multiplicationPassed = testPolynomialMultiplication();
    divisionPassed = testPolynomialDivision();    
    powerPassed = testPolynomialPower();

    // Return non-zero if any tests fail
    bool Polynomial_tests_passed = additionPassed && subtractionPassed && multiplicationPassed && divisionPassed && powerPassed;

    testPolynomialDivisionBig();
    testPolynomialMultiplyDivide();
    testRemainderDivision();

    return 0;
}