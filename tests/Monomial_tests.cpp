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

// Declare the test functions so main.cpp can call them
extern bool testAddition();
extern bool testSubtraction();