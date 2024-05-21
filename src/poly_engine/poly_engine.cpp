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
    std::map<Monomial, double> terms;  // Map monomials to coefficients for unique identification

public:
    void addMonomial(double coefficient, const std::vector<int>& exponents) {
        Monomial m(coefficient, exponents);
        terms[m] += coefficient;  // This automatically handles adding or updating terms
        if (terms[m] == 0) {
            terms.erase(m);  // Erase the term if the coefficient becomes zero
        }
    }

    void print() const {
        if (terms.empty()) {
            std::cout << "0";
            return;
        }
        for (const auto& pair : terms) {
            std::cout << pair.second << " * ";
            for (size_t i = 0; i < pair.first.exponents.size(); ++i) {
                if (pair.first.exponents[i] != 0) {
                    std::cout << "x_" << i << "^" << pair.first.exponents[i];
                    if (i < pair.first.exponents.size() - 1) std::cout << " * ";
                }
            }
            std::cout << " + ";
        }
        std::cout << "\b\b  "; // Remove the last "+ "
    }
};

int main() {
    MultivariablePolynomial poly;
    poly.addMonomial(3.5, {2, 1});  // 3.5 * x^2 * y^1
    poly.addMonomial(-2.0, {0, 3}); // -2.0 * y^3
    poly.addMonomial(1.0, {1, 0});  // 1.0 * x^1

    poly.print();
    std::cout << std::endl;
    return 0;
}