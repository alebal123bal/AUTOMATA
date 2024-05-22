#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

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

    bool operator==(const Monomial& other) const {
        return (coefficient == other.coefficient) && (exponents == other.exponents);
    }
};

class MultivariablePolynomialFraction {
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

    // Addition of polynomial fractions
    MultivariablePolynomialFraction operator+(const MultivariablePolynomialFraction& other) {
        MultivariablePolynomialFraction result;

        // Direct addition if denominators are the same
        if (this->den_terms == other.den_terms) {
            for (auto& term : this->num_terms) {
                result.num_addMonomial(term.second, term.first.exponents);
            }
            for (auto& term : other.num_terms) {
                result.num_addMonomial(term.second, term.first.exponents);
            }
            result.den_terms = this->den_terms; // Copy any denominator since they are the same
        } else {
            // LCM of denominators needed, simplified approach: multiply the denominators
            for (auto& this_term : this->num_terms) {
                for (auto& other_den_term : other.den_terms) {
                    std::vector<int> new_exponents = max_exponents(this_term.first.exponents, other_den_term.first.exponents);
                    result.num_addMonomial(this_term.second * other_den_term.second, new_exponents);
                }
            }
            for (auto& other_term : other.num_terms) {
                for (auto& this_den_term : this->den_terms) {
                    std::vector<int> new_exponents = max_exponents(other_term.first.exponents, this_den_term.first.exponents);
                    result.num_addMonomial(other_term.second * this_den_term.second, new_exponents);
                }
            }
            for (auto& this_den : this->den_terms) {
                for (auto& other_den : other.den_terms) {
                    std::vector<int> new_exponents = max_exponents(this_den.first.exponents, other_den.first.exponents);
                    result.den_addMonomial(this_den.second * other_den.second, new_exponents);
                }
            }
        }

        return result;
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
        static const char* var_names[] = {"x", "y", "z"}; // Extend this as needed
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
                    std::cout << var_names[i] << "^" << pair.first.exponents[i];
                    firstVar = false;
                }
            }
        }
    }

    std::vector<int> max_exponents(const std::vector<int>& a, const std::vector<int>& b) const {
        std::vector<int> result(std::max(a.size(), b.size()), 0);
        for (size_t i = 0; i < result.size(); ++i) {
            int exp_a = i < a.size() ? a[i] : 0;
            int exp_b = i < b.size() ? b[i] : 0;
            result[i] = std::max(exp_a, exp_b);
        }
        return result;
    }
};

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