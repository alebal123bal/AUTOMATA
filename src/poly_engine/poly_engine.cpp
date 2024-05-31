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

int main() {
    // MultivariablePolynomial poly1;
    // poly1.addMonomial(3.5, {2, 1});  // 3.5 * x^2 * y^1
    // poly1.addMonomial(-2.0, {0, 3}); // -2.0 * y^3
    // poly1.addMonomial(1.0, {1, 0});  // 1.0 * x^1

    // MultivariablePolynomial poly2;
    // poly2.addMonomial(2.0, {0, 1});  // 2.0 * y^1
    // poly2.addMonomial(1.0, {2, 0});  // 1.0 * x^2
    // poly2.addMonomial(1.0, {0, 1});  // y

    bool additionPassed = testAddition();
    bool subtractionPassed = testSubtraction();

    // Return non-zero if any tests fail
    return (additionPassed && subtractionPassed) ? 0 : 1;
    std::cout << std::endl;
    return 0;
}