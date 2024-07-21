import sys
import os

# Add the build/bin directory to the system path
sys.path.append('/mnt/c/Users/Alessandro/OneDrive/Desktop/programs/AUTOMATA/build/bin')

# Import the module
import automata_bindings

# Test functionality
print("Module imported successfully")


# Define two polynomials

# Create monomials for P(x, y)
monomials_A = [
    automata_bindings.Monomial(1, [2, 0]),  # x^2
    automata_bindings.Monomial(2, [1, 1]),  # 2xy
    automata_bindings.Monomial(1, [0, 2])   # y^2
]

# Create monomials for Q(x, y)
monomials_B = [
    automata_bindings.Monomial(1, [3, 0]),  # x^3
    automata_bindings.Monomial(1, [0, 3])   # y^3
]

# Create polynomials from monomials
A = automata_bindings.MultivariablePolynomial(monomials_A)
B = automata_bindings.MultivariablePolynomial(monomials_B)

# Perform polynomial multiplication
product = A * B

print(f"Product: {product.print()}")

# Perform polynomial division on the new polynomial
quotient, remainder = product / A

# Print the quotient and remainder
print("Quotient:")
quotient.print()

print("\nRemainder:")
remainder.print()