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

    // Expected result is -2x^2y + 4xy^3
    MultivariablePolynomial expected;
    expected.addMonomial(-2, {2, 1}); // -2x^2y
    expected.addMonomial(4, {1, 3}); // 4xy^3

    // Sub the two polynomials
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

bool testPolynomialMultiplication() {
    // Create first polynomial 3x^2y + 2xy^3
    MultivariablePolynomial poly1;
    poly1.addMonomial(3, {2, 1});  // 3x^2y
    poly1.addMonomial(2, {1, 3});  // 2xy^3

    // Create second polynomial 5x^2y - 2xy^3
    MultivariablePolynomial poly2;
    poly2.addMonomial(5, {2, 1});  // 5x^2y
    poly2.addMonomial(-2, {1, 3}); // -2xy^3

    // Multiply the polynomials
    MultivariablePolynomial result = poly1 * poly2;

    // Expected result 15x^4y^2 + 4x^3y^4 - 4x^2y^6
    MultivariablePolynomial expected;
    expected.addMonomial(15, {4, 2}); // 15x^4y^2
    expected.addMonomial(4, {3, 4});  // 4x^3y^4
    expected.addMonomial(-4, {2, 6}); // -4x^2y^6

    // Assert to check if the result matches the expected result
    if (result == expected) {
        std::cout << "MultivariablePolynomial Multiplication test passed." << std::endl;
        return true;
    } else {
        std::cout << "MultivariablePolynomial Multiplication test failed." << std::endl;
        return false;
    }
}

bool testPolynomialPower() {
    // Create a simple polynomial, p(x) = 1 + x
    MultivariablePolynomial p;
    p.addMonomial(1, {0});  // Constant term: 1
    p.addMonomial(1, {1});  // Linear term: x

    // Compute p(x)^3 = (1 + x)^3 = 1 + 3x + 3x^2 + x^3
    MultivariablePolynomial p_cubed = p.pow(3);
    MultivariablePolynomial expected_p_cubed;
    expected_p_cubed.addMonomial(1, {0});  // 1
    expected_p_cubed.addMonomial(3, {1});  // 3x
    expected_p_cubed.addMonomial(3, {2});  // 3x^2
    expected_p_cubed.addMonomial(1, {3});  // x^3

    // Assert to check if the result matches the expected result
    assert(p_cubed == expected_p_cubed);

    // Compute p(x)^0 = 1 (any polynomial to the zero power should be 1)
    MultivariablePolynomial p_zero = p.pow(0);
    MultivariablePolynomial expected_p_zero;
    expected_p_zero.addMonomial(1, {0});  // 1

    assert(p_zero == expected_p_zero);

    // Compute p(x)^1 = p(x) (any polynomial to the first power should be the polynomial itself)
    MultivariablePolynomial p_one = p.pow(1);
    assert(p_one == p);

    std::cout << "All power tests passed." << std::endl;
}

extern bool testPolynomialAddition();
extern bool testPolynomialSubtraction();
extern bool testPolynomialMultiplication();
extern bool testPolynomialPower();