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
extern bool testPolynomialMultiplication();
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
    
    powerPassed = testPolynomialPower();

    //Lets see how fast is this power
    MultivariablePolynomial p;
    p.addMonomial(1, {1});  // Linear term: x
    p.addMonomial(1, {0, 1});  // Cubic term: y
    p.print();

    //TODO: check this for more than one variable
    MultivariablePolynomial p_5 = p.pow(2);
    p_5.print();

    std::cout << p_5.eval({2.71, 1});

    return 0;
}