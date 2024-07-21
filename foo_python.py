import sys
import os
import botorch

# Add the build/bin directory to the system path
sys.path.append('/mnt/c/Users/Alessandro/OneDrive/Desktop/programs/AUTOMATA/build/bin')

# Import the module
import automata_bindings

# Test functionality
print("Module imported successfully")


# Define two polynomials
# For example, let's say we have two polynomials P(x, y) and Q(x, y)
# P(x, y) = 3x^2y + 2xy^2 + y^3
# Q(x, y) = x + y

# Create monomials for P(x, y)
monomials_P = [
    automata_bindings.Monomial(3, [2, 1]),  # 3x^2y
    automata_bindings.Monomial(2, [1, 2]),  # 2xy^2
    automata_bindings.Monomial(1, [0, 3])   # y^3
]

# Create monomials for Q(x, y)
monomials_Q = [
    automata_bindings.Monomial(1, [1, 0]),  # x
    automata_bindings.Monomial(1, [0, 1])   # y
]

# Create polynomials from monomials
P = automata_bindings.MultivariablePolynomial(monomials_P)
Q = automata_bindings.MultivariablePolynomial(monomials_Q)

# Perform polynomial division
quotient, remainder = P / Q

# Print the quotient and remainder
print("Quotient:")
quotient.print()

print("\nRemainder:")
remainder.print()