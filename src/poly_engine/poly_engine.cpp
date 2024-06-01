#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Monomial.h"
#include "MultivariablePolynomial.h"
#include "MultivariablePolynomialFraction.h"

//TODO: copy the MultivariablePolynomialFraction class
//into MultivariablePolynomial 
//with the same functions but of course without the denominator problems
extern bool testAddition();
extern bool testSubtraction();
extern bool testMultiplication();
extern bool testDivision();
extern bool testPow();

extern bool testPolynomialAddition();
extern bool testPolynomialSubtraction();

int main() {
    bool additionPassed = testAddition();
    bool subtractionPassed = testSubtraction();
    bool multiplicationPassed = testMultiplication();
    bool divisionPassed = testDivision();
    bool powerPassed = testPow();

    // Return non-zero if any tests fail
    //return (additionPassed && subtractionPassed && multiplicationPassed && divisionPassed && powerPassed) ? 0 : 1;
    testPolynomialAddition();
    testPolynomialSubtraction();
    return 0;
}