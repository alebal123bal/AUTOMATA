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
extern bool testPolynomialDivisionSmall();
extern bool testPolynomialDivisionNoSymbols();
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

    bool advanced_0 = testPolynomialDivisionBig();
    bool advanced_1 = testPolynomialDivisionSmall();
    bool advanced_2 = testPolynomialDivisionNoSymbols();
    bool advanced_3 = testPolynomialMultiplyDivide();
    bool advanced_4 = testRemainderDivision();

    // Return non-zero if any tests fail
    bool advanced_Polynomial_tests_passed = advanced_0 && advanced_1 && advanced_2 && advanced_3 && advanced_4;

    return 0;
}