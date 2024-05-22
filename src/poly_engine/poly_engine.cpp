#include <iostream>
#include <map>
#include <vector>

struct Monomial {
    double coefficient;
    std::vector<int> exponents;

    Monomial(double coeff, const std::vector<int>& exps)
        : coefficient(coeff), exponents(exps) {}

    bool operator<(const Monomial& other) const {
        if (exponents.size() != other.exponents.size()) {
            return exponents.size() < other.exponents.size();
        }
        return exponents < other.exponents;
    }
};

class MultivariablePolynomial {
private:
    std::map<Monomial, double> num_terms;  // Map monomials to coefficients for unique identification
    std::map<Monomial, double> den_terms;  // Map monomials to coefficients for unique identification

public:
    void num_addMonomial(double coefficient, const std::vector<int>& exponents) {
        Monomial m(coefficient, exponents);
        num_terms[m] += coefficient;
        if (num_terms[m] == 0) {
            num_terms.erase(m);
        }
    }
    
    void den_addMonomial(double coefficient, const std::vector<int>& exponents) {
        Monomial m(coefficient, exponents);
        den_terms[m] += coefficient;
        if (den_terms[m] == 0) {
            den_terms.erase(m);
        }
    }

    void print() const {
        printTerms(num_terms);
        if (den_terms.size() == 1 && den_terms.begin()->first.exponents.empty() && den_terms.begin()->second == 1.0) {
            // If the denominator is just 1, do not print it.
        } else if (!den_terms.empty()) {
            std::cout << " / ";
            printTerms(den_terms);
        }
    }

private:
    void printTerms(const std::map<Monomial, double>& terms) const {
        if (terms.empty()) {
            std::cout << "0";
            return;
        }
        bool first = true;
        for (const auto& pair : terms) {
            if (!first) {
                std::cout << " + ";
            }
            first = false;

            std::cout << pair.second;
            bool firstVar = true;
            for (size_t i = 0; i < pair.first.exponents.size(); ++i) {
                if (pair.first.exponents[i] != 0) {
                    if (!firstVar) {
                        std::cout << " * ";
                    }
                    std::cout << "x_" << i << "^" << pair.first.exponents[i];
                    firstVar = false;
                }
            }
        }
    }
};

int main() {
    MultivariablePolynomial poly;
    poly.num_addMonomial(3.5, {2, 1});  // 3.5 * x^2 * y^1
    poly.num_addMonomial(-2.0, {0, 3}); // -2.0 * y^3
    poly.num_addMonomial(1.0, {1, 0});  // 1.0 * x^1

    poly.den_addMonomial(1.0, {0, 0});  // Unity

    poly.print();
    std::cout << std::endl;
    return 0;
}