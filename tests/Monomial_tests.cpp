#include "Monomial.h"
#include <iostream>

// Test functions
bool testAddition() {
    Monomial mono1(2.0, {1, 2});
    Monomial mono2(3.0, {1, 2});
    Monomial expectedSum(5.0, {1, 2});
    Monomial resultSum = mono1 + mono2;

    if (resultSum == expectedSum) {
        std::cout << "Monomial Addition test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Addition test failed." << std::endl;
        return false;
    }
}

bool testSubtraction() {
    Monomial mono1(2.0, {1, 2});
    Monomial mono2(3.0, {1, 2});
    Monomial expectedDiff(-1.0, {1, 2});
    Monomial resultDiff = mono1 - mono2;

    if (resultDiff == expectedDiff) {
        std::cout << "Monomial Subtraction test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Subtraction test failed." << std::endl;
        return false;
    }
}

bool testMultiplication() {
    Monomial mono1(4.0, {2, 3});
    Monomial mono2(5.0, {1, 1});
    Monomial expectedProduct(20.0, {3, 4});
    Monomial resultProduct = mono1 * mono2;

    if (resultProduct == expectedProduct) {
        std::cout << "Monomial Multiplication test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Multiplication test failed." << std::endl;
        return false;
    }
}

bool testScalarMultiplication() {
    double coeff = 5.0;
    Monomial mono1(4.0, {2, 3});
    Monomial expectedProduct(20.0, {2, 3});
    Monomial resultProduct = coeff * mono1;
    Monomial resultProduct_back = mono1 * coeff;

    if (resultProduct == expectedProduct && resultProduct_back == expectedProduct) {
        std::cout << "Monomial Scalar Multiplication test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Scalar Multiplication test failed." << std::endl;
        return false;
    }
}

bool testDivision() {
    Monomial mono1(10.0, {5, 6});
    Monomial mono2(2.0, {3, 2});
    Monomial expectedQuotient(5.0, {2, 4});
    Monomial resultQuotient = mono1 / mono2;

    if (resultQuotient == expectedQuotient) {
        std::cout << "Monomial Division test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Division test failed." << std::endl;
        return false;
    }
}

bool testPow() {
    Monomial mono(2.0, {1, 2});  // Represents 2*x*y^2
    int exponent = -3;
    Monomial result = mono.pow(exponent);
    Monomial expected(0.125, {-3, -6});  // Should be 8*x^3*y^6

    if (result == expected) {
        std::cout << "Monomial Power test passed." << std::endl;
        return true;
    } else {
        std::cout << "Monomial Power test failed." << std::endl;
        return false;
    }
}

// Declare the test functions so main.cpp can call them
extern bool testAddition();
extern bool testSubtraction();
extern bool testMultiplication();
extern bool testScalarMultiplication();
extern bool testDivision();
extern bool testPow();