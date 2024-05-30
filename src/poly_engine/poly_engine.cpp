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

int main() {
    MultivariablePolynomialFraction poly1;
    poly1.num_addMonomial(3.5, {2, 1});  // 3.5 * x^2 * y^1
    poly1.num_addMonomial(-2.0, {0, 3}); // -2.0 * y^3
    poly1.num_addMonomial(1.0, {1, 0});  // 1.0 * x^1
    poly1.den_addMonomial(1.0, {1, 0});  // x

    MultivariablePolynomialFraction poly2;
    poly2.num_addMonomial(2.0, {0, 1});  // 2.0 * y^1
    poly2.num_addMonomial(1.0, {2, 0});  // 1.0 * x^2
    poly2.den_addMonomial(1.0, {0, 1});  // y

    MultivariablePolynomialFraction result = poly1 + poly2;
    result.print();
    std::cout << std::endl;
    return 0;
}