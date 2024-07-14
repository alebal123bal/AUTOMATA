#include "MultivariablePolynomial.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <chrono>

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
        std::cout << "testPolynomialAddition passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialAddition failed." << std::endl;
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
        std::cout << "testPolynomialSubtraction passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialSubtraction failed." << std::endl;
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
        std::cout << "testPolynomialMultiplication passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialMultiplication failed." << std::endl;
        return false;
    }
}

bool testPolynomialDivisionBig(){
    // Create the first (dividend) polynomial: 3x^4y^2 + 15x^3y^3 + 4x^3y^2 + 22x^2y^3 + 10xy^4
    MultivariablePolynomial poly1;
    poly1.addMonomial(15, {3, 3});   // 15x^3y^3    voluntarely inverted this line with the next
    poly1.addMonomial(3, {4, 2});   // 3x^4y^2
    poly1.addMonomial(22, {2, 3});   // 22x^2y^3    voluntarely inverted this line with the next
    poly1.addMonomial(4, {3, 2});  // 4x^3y^2
    poly1.addMonomial(10, {1, 4});  // 10xy^4

    // Create the divisor polynomial: x^2y + 5xy^2
    MultivariablePolynomial poly2;
    poly2.addMonomial(5, {1, 2});   // 5xy^2
    poly2.addMonomial(1, {2, 1});   // x^2y
    
    // Divide the polynomials
    std::pair<MultivariablePolynomial, MultivariablePolynomial> results = poly1 / poly2;

    // Expected result 3x^2y + 4xy + 2y^2
    MultivariablePolynomial expected;
    expected.addMonomial(3, {2, 1}); // 3x^2y
    expected.addMonomial(4, {1, 1});  // 4xy
    expected.addMonomial(2, {0, 2}); // 2y^2

    // Assert to check if the result matches the expected result
    if (results.first == expected) {
        std::cout << "testPolynomialDivisionBig test passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialDivisionBig failed." << std::endl;
        return false;
    }

}


bool testPolynomialDivisionSmall() {
    // Create first polynomial
    MultivariablePolynomial poly1;
    poly1.addMonomial(1, {2, 0});  // x^2
    poly1.addMonomial(-1, {0, 0});  // -1

    // Create second polynomial x + 1
    MultivariablePolynomial poly2;
    poly2.addMonomial(1, {1, 0});  // x
    poly2.addMonomial(1, {0, 0}); // 1

    // Divide the polynomials
    std::pair<MultivariablePolynomial, MultivariablePolynomial> results = poly1 / poly2;

    // Expected result x - 1
    MultivariablePolynomial expected;
    expected.addMonomial(1, {1, 0}); // x
    expected.addMonomial(-1, {0, 0});  // -1

    // Assert to check if the result matches the expected result
    if (results.first == expected) {
        std::cout << "testPolynomialDivisionSmall passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialDivisionSmall failed: not a dividend." << std::endl;
        return false;
    }
}

bool testPolynomialDivisionNoSymbols() {
    // Create first number
    MultivariablePolynomial poly1;
    poly1.addMonomial(14, {0, 0});  // 14

    // Create second number
    MultivariablePolynomial poly2;
    poly2.addMonomial(2, {0, 0}); // 1

    // Divide the polynomials
    std::pair<MultivariablePolynomial, MultivariablePolynomial> results = poly1 / poly2;

    // Expected result 7
    MultivariablePolynomial expected;
    expected.addMonomial(7, {0, 0});  // 7

    // Assert to check if the result matches the expected result
    if (results.first == expected) {
        std::cout << "testPolynomialDivisionNoSymbols passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialDivisionNoSymbols failed: not a dividend." << std::endl;
        return false;
    }
}

bool testPolynomialDivision() {
    // Create first polynomial
    MultivariablePolynomial poly1;
    poly1.addMonomial(2, {3, 0});  // 2x^3
    poly1.addMonomial(12, {2, 1});  // 12x^2y
    poly1.addMonomial(15, {1, 2});  // 15xy^2
    poly1.addMonomial(-9, {0, 3});  // -9y^3

    // Create second polynomial x + 3y
    MultivariablePolynomial poly2;
    poly2.addMonomial(1, {1, 0});  // x
    poly2.addMonomial(3, {0, 1}); // 3y

    // Divide the polynomials
    std::pair<MultivariablePolynomial, MultivariablePolynomial> results = poly1 / poly2;

    // Expected result 2x^2 + 6xy - 3y^2
    MultivariablePolynomial expected;
    expected.addMonomial(2, {2, 0}); // 2x^2
    expected.addMonomial(6, {1, 1});  // 6xy
    expected.addMonomial(-3, {0, 2}); // -3y^2

    // Assert to check if the result matches the expected result
    if (results.first == expected) {
        std::cout << "testPolynomialDivision passed." << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialDivision failed: not a dividend." << std::endl;
        return false;
    }
}

//Now the big poly gets "created" through a big multiplication (power eventually) and then divided
bool testPolynomialMultiplyDivide(){    
    // Start timing
    auto start_time = std::chrono::high_resolution_clock::now();

    int exponent = 50;

    // Create first polynomial x + 3y
    MultivariablePolynomial poly1;
    poly1.addMonomial(1, {1, 0});  // x
    poly1.addMonomial(3, {0, 1}); // 3y

    //Power it to the 35th
    MultivariablePolynomial poly2 = poly1.pow(exponent);

    //Try division: let's check how fast it is
    std::pair<MultivariablePolynomial, MultivariablePolynomial> poly3 = poly1 / poly2;

    //Eventually evaluate it numerically but with super small values
    double res_true = poly2.eval({0.005, 0.007}) / poly1.eval({0.5, 0.7});
    double my_res = poly3.first.eval({0.005, 0.007});

    // Assert to check if the result matches the expected result
    if (std::fabs(my_res - res_true) <= MathConstants::EPSILON) {
        // Measure elapsed time
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        std::cout << "testPolynomialMultiplyDivide passed. Time elapsed: " << duration << " ms. Exponent " << exponent << std::endl;
        return true;
    } else {
        std::cout << "testPolynomialMultiplyDivide failed. . Exponent " << exponent << std::endl;
        return false;
    }
}

//Create a mock polynomial through a multiplication, and then divide it with a smaller one.
//Multiply back the quotient with the divisor and add the remainder. Numerical eval will tell correctness.
bool testRemainderDivision(){
    MultivariablePolynomial poly1;
    poly1.addMonomial(2, {3, 0});  // 2x^3
    poly1.addMonomial(12, {2, 1});  // 12x^2y
    poly1.addMonomial(11, {3, 2});  // 11x^3y^2
    
    MultivariablePolynomial poly2;
    poly2.addMonomial(1, {1, 0});  // x
    poly2.addMonomial(3, {0, 1}); // 3y

    MultivariablePolynomial poly3 = poly1 * poly2;

    //Try this dividend
    MultivariablePolynomial poly4;
    poly4.addMonomial(1, {2, 0});  // x^2
    poly4.addMonomial(1, {0, 1}); // y

    std::pair<MultivariablePolynomial, MultivariablePolynomial> results = poly3 / poly4;

    std::vector<double> values = {0.005, 0.007};

    //Invert procedure
    double correct_res = poly3.eval(values);
    double my_res = results.first.eval(values) * poly4.eval(values) + results.second.eval(values);

    // Assert to check if the result matches the expected result
    if (std::fabs(my_res - correct_res) <= MathConstants::EPSILON) {
        std::cout << "testRemainderDivision passed." << std::endl;
        return true;
    } else {
        std::cout << "testRemainderDivision failed." << std::endl;
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
        std::cout << "testPolynomialPower failed." << std::endl;
        return false;
    }

    // Compute p(x)^0 = 1 (any polynomial to the zero power should be 1)
    MultivariablePolynomial p_zero = p.pow(0);
    MultivariablePolynomial expected_p_zero;
    expected_p_zero.addMonomial(1, {0, 0});  // 1

    if (!(p_zero == expected_p_zero)) {
        std::cout << "testPolynomialPower failed: p(x)^0 did not match the expected polynomial of 1." << std::endl;
        return false;
    }

    // Compute p(x)^1 = p(x) (any polynomial to the first power should be the polynomial itself)
    MultivariablePolynomial p_one = p.pow(1);
    if (!(p_one == p)) {
        std::cout << "testPolynomialPower failed: p(x)^1 did not match the original polynomial p(x)." << std::endl;
        return false;
    }

    std::cout << "testPolynomialPower passed." << std::endl;
    return true;
}


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