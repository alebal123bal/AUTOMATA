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

bool testPolynomialDivision() {
    // Create first polynomial
    MultivariablePolynomial poly1;
    poly1.addMonomial(2, {3, 0});  // 2x^2
    poly1.addMonomial(12, {2, 1});  // 12x^2y
    poly1.addMonomial(15, {1, 2});  // 15xy^2
    poly1.addMonomial(-9, {0, 3});  // -9y^3

    // Create second polynomial x + 3y
    MultivariablePolynomial poly2;
    poly2.addMonomial(1, {1, 0});  // x
    poly2.addMonomial(3, {0, 1}); // 3y

    // Multiply the polynomials
    MultivariablePolynomial result = poly1 / poly2;

    // Expected result 2x^2 + 6xy - 3y^2
    MultivariablePolynomial expected;
    expected.addMonomial(2, {2, 0}); // 2x^2
    expected.addMonomial(6, {1, 1});  // 6xy
    expected.addMonomial(-3, {0, 2}); // -3y^2

    // Assert to check if the result matches the expected result
    if (result == expected) {
        std::cout << "MultivariablePolynomial Division test passed." << std::endl;
        return true;
    } else {
        std::cout << "MultivariablePolynomial Division test failed: not a dividend." << std::endl;
        return false;
    }
}

bool testPolynomialPower() {
    // Create a simple polynomial, p(x) = 1 + x
    MultivariablePolynomial p;
    p.addMonomial(1, {0, 0});  // Constant term: 1
    p.addMonomial(1, {1, 0});  // Linear term: x

    // Compute p(x)^3 = (1 + x)^3 = 1 + 3x + 3x^2 + x^3
    MultivariablePolynomial p_cubed = p.pow(3);
    MultivariablePolynomial expected_p_cubed;
    expected_p_cubed.addMonomial(1, {0, 0});  // 1
    expected_p_cubed.addMonomial(3, {1, 0});  // 3x
    expected_p_cubed.addMonomial(3, {2, 0});  // 3x^2
    expected_p_cubed.addMonomial(1, {3, 0});  // x^3

    // Check if the results match the expected results
    if (!(p_cubed == expected_p_cubed)) {
        std::cout << "Test failed: p(x)^3 did not match the expected polynomial." << std::endl;
        return false;
    }

    // Compute p(x)^0 = 1 (any polynomial to the zero power should be 1)
    MultivariablePolynomial p_zero = p.pow(0);
    MultivariablePolynomial expected_p_zero;
    expected_p_zero.addMonomial(1, {0, 0});  // 1

    if (!(p_zero == expected_p_zero)) {
        std::cout << "Test failed: p(x)^0 did not match the expected polynomial of 1." << std::endl;
        return false;
    }

    // Compute p(x)^1 = p(x) (any polynomial to the first power should be the polynomial itself)
    MultivariablePolynomial p_one = p.pow(1);
    if (!(p_one == p)) {
        std::cout << "Test failed: p(x)^1 did not match the original polynomial p(x)." << std::endl;
        return false;
    }

    std::cout << "All Polynomial Power tests passed." << std::endl;
    return true;
}

extern bool testPolynomialAddition();
extern bool testPolynomialSubtraction();
extern bool testPolynomialMultiplication();
extern bool testPolynomialDivision();
extern bool testPolynomialPower();