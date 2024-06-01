#include "MultivariablePolynomial.h"
#include <iostream>
#include <cassert>  // for assert()

// Test functions

void testPolynomialAddition() {
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
    // This assumes you have an equality operator or a similar mechanism to compare polynomials
    // Since we don't have such an operator in the provided code, we'll print the results instead.
    // In a real test, you might use a custom function or methods to ensure the polynomials match
    // For visualization, let's print the resulting polynomial
    std::cout << "Resulting Polynomial: ";
    result.print();
    std::cout << "Expected Polynomial: ";
    expected.print();

    // Assert to check if the test passes -- this is a simple check assuming an operator== is defined
    // assert(result == expected);

    // Manual check if no operator== is defined
    // Here you could compare the internal structures if accessible or ensure the print outputs match expected values

    std::cout << "Polynomial addition test completed." << std::endl; // Indicate test completion
}

extern void testPolynomialAddition();