#include "Monomial.h"
#include <iostream>

// Test functions
bool testAddition() {
    Monomial mono1(2.0, {1, 2});
    Monomial mono2(3.0, {1, 2});
    Monomial expectedSum(5.0, {1, 2});
    Monomial resultSum = mono1 + mono2;

    if (resultSum == expectedSum) {
        std::cout << "Addition test passed." << std::endl;
        return true;
    } else {
        std::cout << "Addition test failed." << std::endl;
        return false;
    }
}

bool testSubtraction() {
    Monomial mono1(2.0, {1, 2});
    Monomial mono2(3.0, {1, 2});
    Monomial expectedDiff(-1.0, {1, 2});
    Monomial resultDiff = mono1 - mono2;

    if (resultDiff == expectedDiff) {
        std::cout << "Subtraction test passed." << std::endl;
        return true;
    } else {
        std::cout << "Subtraction test failed." << std::endl;
        return false;
    }
}

bool testMultiplication() {
    Monomial mono1(4.0, {2, 3});
    Monomial mono2(5.0, {1, 1});
    Monomial expectedProduct(20.0, {3, 4});
    Monomial resultProduct = mono1 * mono2;

    if (resultProduct == expectedProduct) {
        std::cout << "Multiplication test passed." << std::endl;
        return true;
    } else {
        std::cout << "Multiplication test failed." << std::endl;
        return false;
    }
}

bool testDivision() {
    Monomial mono1(10.0, {5, 6});
    Monomial mono2(2.0, {3, 2});
    Monomial expectedQuotient(5.0, {2, 4});
    Monomial resultQuotient = mono1 / mono2;

    if (resultQuotient == expectedQuotient) {
        std::cout << "Division test passed." << std::endl;
        return true;
    } else {
        std::cout << "Division test failed." << std::endl;
        return false;
    }
}

bool testPow() {
    Monomial mono(2.0, {1, 2});  // Represents 2*x*y^2
    int exponent = -3;
    Monomial result = mono.pow(exponent);
    Monomial expected(0.125, {-3, -6});  // Should be 8*x^3*y^6

    if (result == expected) {
        std::cout << "Power test passed." << std::endl;
        return true;
    } else {
        std::cout << "Power test failed." << std::endl;
        return false;
    }
}

// Declare the test functions so main.cpp can call them
extern bool testAddition();
extern bool testSubtraction();
extern bool testMultiplication();
extern bool testDivision();
extern bool testPow();