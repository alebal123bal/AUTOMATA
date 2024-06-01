#include "MultivariablePolynomial.h"
#include <iostream>
#include <cassert>  // for assert()

// Test functions

bool testPolynomialAddition() {
    // Create first polynomial with monomials 3x^2y and 2xy^3
    MultivariablePolynomial poly1;
    poly1.addMonomial(3, {2, 1});  // 3x^2y
    poly1.addMonomial(2, {1, 3});  // 2xy^3

    // Create second polynomial with monomials 5x^2y and -2xy^3
    MultivariablePolynomial poly2;
    poly2.addMonomial(5, {2, 1});  // 5x^2y
    poly2.addMonomial(-2, {1, 3}); // -2xy^3

    // Expected result is 8x^2y
    MultivariablePolynomial expected;
    expected.addMonomial(8, {2, 1}); // 8x^2y

    // Add the two polynomials
    MultivariablePolynomial result = poly1 + poly2;

    // Test if the result matches the expected result
    if (result == expected) {
        std::cout << "MultivariablePolynomial Addition test passed." << std::endl;
        return true;
    } else {
        std::cout << "MultivariablePolynomial Addition test failed." << std::endl;
        return false;
    }
}

bool testPolynomialSubtraction() {
    // Create first polynomial with monomials 3x^2y and 2xy^3
    MultivariablePolynomial poly1;
    poly1.addMonomial(3, {2, 1});  // 3x^2y
    poly1.addMonomial(2, {1, 3});  // 2xy^3

    // Create second polynomial with monomials 5x^2y and -2xy^3
    MultivariablePolynomial poly2;
    poly2.addMonomial(5, {2, 1});  // 5x^2y
    poly2.addMonomial(-2, {1, 3}); // -2xy^3

    // Expected result is 8x^2y
    MultivariablePolynomial expected;
    expected.addMonomial(-2, {2, 1}); // -2x^2y
    expected.addMonomial(4, {1, 3}); // 4xy^3

    // Add the two polynomials
    MultivariablePolynomial result = poly1 - poly2;

    // Test if the result matches the expected result
    if (result == expected) {
        std::cout << "MultivariablePolynomial Subtraction test passed." << std::endl;
        return true;
    } else {
        std::cout << "MultivariablePolynomial Subtraction test failed." << std::endl;
        return false;
    }
}

extern bool testPolynomialAddition();
extern bool testPolynomialSubtraction();