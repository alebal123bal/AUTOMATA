# AUTOMATA

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
  - [1. Clone the Repository](#1-clone-the-repository)
  - [2. Install Dependencies](#2-install-dependencies)
  - [3. Build the Project with CMake](#3-build-the-project-with-cmake)
  - [4. Build Python Bindings](#4-build-python-bindings)
- [Usage](#usage)
  - [Using the C++ Library](#using-the-c-library)
  - [Using the Python Bindings](#using-the-python-bindings)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Overview

**AUTOMATA** is a versatile C++ library designed for handling multivariate polynomials. It provides classes and operations for creating, manipulating, and evaluating polynomials with multiple variables. Additionally, AUTOMATA includes Python bindings using **pybind11**, allowing seamless integration with Python for scientific computing and symbolic mathematics applications.

## Features

- **Monomial Representation:** Define monomials with coefficients and exponents.
- **Polynomial Operations:** Perform addition, subtraction, multiplication, division, and exponentiation on multivariate polynomials.
- **Scalar Operations:** Multiply monomials and polynomials by scalar values.
- **Evaluation:** Numerically evaluate polynomials given specific variable values.
- **Operator Overloading:** Intuitive mathematical operations through overloaded operators.
- **Cleanup Mechanism:** Simplify polynomials by combining like terms.
- **Python Bindings:** Access and manipulate polynomials directly from Python.
- **Comprehensive Testing:** Ensure reliability with extensive unit tests.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- **Operating System:** Windows, macOS, or Linux
- **Compiler:** A C++ compiler that supports C++11 or higher (e.g., `g++`, `clang++`, or MSVC)
- **CMake:** Version 3.10 or higher
- **Python:** Version 3.6 or higher (for Python bindings)
- **Python Packages:**
  - `pybind11`
  - `numpy` (if using Python bindings)
- **Additional Tools:**
  - `Git` (for cloning the repository)

## Installation

### 1. Clone the Repository

First, clone the AUTOMATA repository to your local machine:

```bash
git clone https://github.com/alebal123bal/AUTOMATA.git
cd automata
```

### 2. Install Dependencies

It's recommended to use a virtual environment to manage Python dependencies, especially if you plan to use the Python bindings.

**Using `venv`:**

```bash
python3 -m venv env
source env/bin/activate  # On Windows: env\Scripts\activate
pip install --upgrade pip
pip install pybind11 numpy
```

### 3. Build the Project with CMake

AUTOMATA uses **CMake** to manage the build process. Follow these steps to configure and build the project.

#### a. Create a Build Directory

Create a separate directory for building the project to keep the source directory clean:

```bash
mkdir build
cd build
```

#### b. Configure the Project

Run CMake to configure the project. This step generates the necessary build files.

```bash
cmake ..
```

**Notes:**
- If you want to specify a particular compiler or generator, you can add additional flags. For example, to specify GCC:

  ```bash
  cmake .. -DCMAKE_CXX_COMPILER=g++
  ```

- On Windows, you might need to specify the generator, such as Visual Studio:

  ```bash
  cmake .. -G "Visual Studio 16 2019"
  ```

#### c. Build the Project

Compile the project using the generated build files.

```bash
cmake --build . --config Release
```

**Notes:**
- The `--config Release` flag builds the project in release mode. You can change it to `Debug` if needed.
- On Unix-like systems, you can also use `make`:

  ```bash
  make
  ```

#### d. Verify the Build

After a successful build, you should have the compiled libraries or executables in the `build` directory. Depending on your project setup, you might have static (`.a` or `.lib`) or shared (`.so`, `.dll`, or `.dylib`) libraries.

### 4. Build Python Bindings

AUTOMATA includes Python bindings using **pybind11**, enabling you to use the library directly from Python.

#### a. Ensure `pybind11` is Installed

If you haven't already installed `pybind11`, install it using pip:

```bash
pip install pybind11
```

#### b. Build the Python Module

From the `build` directory, run CMake to include the Python bindings:

```bash
cmake .. -DBUILD_PYTHON_BINDINGS=ON
cmake --build . --config Release
```

**Notes:**
- Ensure that the `CMakeLists.txt` file is properly configured to build the Python bindings when `BUILD_PYTHON_BINDINGS` is enabled.
- The compiled Python module (`automata_bindings.so` on Linux/macOS or `automata_bindings.pyd` on Windows) will be located in the `build` directory.

#### c. Install the Python Module

You can install the Python bindings using pip:

```bash
pip install .
```

Or, manually copy the compiled module to your Python project directory.

## Usage

### Using the C++ Library

The AUTOMATA library provides two primary classes: `Monomial` and `MultivariablePolynomial`. Below are examples demonstrating how to use these classes.

#### Example 1: Creating and Manipulating Monomials

```cpp
#include "Monomial.h"
#include <vector>
#include <iostream>

int main() {
    // Create a monomial 3x^2y^1
    std::vector<int> exponents = {2, 1};
    Monomial mono1(3.0, exponents);

    // Create another monomial 2xy
    std::vector<int> exponents2 = {1, 1};
    Monomial mono2(2.0, exponents2);

    // Add the two monomials
    Monomial sum = mono1 + mono2;
    sum.print(); // Output: 5x^2y^1

    return 0;
}
```

#### Example 2: Creating and Multiplying Polynomials

```cpp
#include "MultivariablePolynomial.h"
#include <vector>
#include <iostream>

int main() {
    // Define monomials for Polynomial A: x^2 + 2xy + y^2
    std::vector<Monomial> monomials_A = {
        Monomial(1.0, {2, 0}),  // x^2
        Monomial(2.0, {1, 1}),  // 2xy
        Monomial(1.0, {0, 2})   // y^2
    };
    MultivariablePolynomial A(monomials_A);

    // Define monomials for Polynomial B: x^3 + y^3
    std::vector<Monomial> monomials_B = {
        Monomial(1.0, {3, 0}),  // x^3
        Monomial(1.0, {0, 3})   // y^3
    };
    MultivariablePolynomial B(monomials_B);

    // Multiply the polynomials: A * B
    MultivariablePolynomial C = A * B;
    C.print(); // Output: 1x^5y^0 + 2x^4y^1 + 3x^3y^3 + 2x^2y^4 + 1x^0y^5

    return 0;
}
```

### Using the Python Bindings

After building the Python bindings, you can use the `automata_bindings` module directly in Python.

#### Example: Multiplying Polynomials in Python

```python
import automata_bindings

# Create monomials for Polynomial A: x^2 + 2xy + y^2
monomials_A = [
    automata_bindings.Monomial(1.0, [2, 0]),
    automata_bindings.Monomial(2.0, [1, 1]),
    automata_bindings.Monomial(1.0, [0, 2]),
]
A = automata_bindings.MultivariablePolynomial(monomials_A)

# Create monomials for Polynomial B: x^3 + y^3
monomials_B = [
    automata_bindings.Monomial(1.0, [3, 0]),
    automata_bindings.Monomial(1.0, [0, 3]),
]
B = automata_bindings.MultivariablePolynomial(monomials_B)

# Multiply the polynomials: A * B
C = A * B

# Print the resulting polynomial
C.print()  # Output: 1x^5y^0 + 2x^4y^1 + 3x^3y^3 + 2x^2y^4 + 1x^0y^5
```

## Testing

AUTOMATA includes a suite of unit tests to ensure the correctness and reliability of its components. The tests cover both the `Monomial` and `MultivariablePolynomial` classes.

### Running Tests

   **Example Output:**

   ```
   Monomial Addition test passed.
   Monomial Subtraction test passed.
   Monomial Multiplication test passed.
   Monomial Scalar Multiplication test passed.
   Monomial Division test passed.
   Monomial Power test passed.
   testPolynomialAddition passed.
   testPolynomialSubtraction passed.
   testPolynomialMultiplication passed.
   testPolynomialDivisionBig passed.
   testPolynomialDivisionSmall passed.
   testPolynomialDivisionNoSymbols passed.
   testPolynomialMultiplyDivide passed.
   testRemainderDivision passed.
   testPolynomialPower passed.
   ```

### Test Structure

- **Monomial Tests:**
  - Addition
  - Subtraction
  - Multiplication
  - Scalar Multiplication
  - Division
  - Power

- **Polynomial Tests:**
  - Addition
  - Subtraction
  - Multiplication
  - Division (Simple and Complex Cases)
  - Remainder Handling
  - Power

**Note:** Ensure all dependencies and test files are correctly referenced in the `CMakeLists.txt` to include the tests in the build process.

## Contributing

Contributions are welcome! Whether you're fixing bugs, improving documentation, or adding new features, your efforts are appreciated. Follow these steps to contribute:

1. **Fork the Repository**

   Navigate to the [AUTOMATA GitHub page](https://github.com/yourusername/automata) and click the "Fork" button.

2. **Clone Your Fork**

   ```bash
   git clone https://github.com/yourusername/autamata.git
   cd automata
   ```

3. **Create a New Branch**

   ```bash
   git checkout -b feature/YourFeature
   ```

4. **Make Your Changes**

   Implement your feature or fix. Ensure that your code adheres to the project's coding standards.

5. **Commit Your Changes**

   ```bash
   git commit -m "Add feature: YourFeature"
   ```

6. **Push to the Branch**

   ```bash
   git push origin feature/YourFeature
   ```

7. **Open a Pull Request**

   Go to your forked repository on GitHub and click "New Pull Request" to submit your changes for review.

**Guidelines:**

- **Code Style:** Follow the existing code style for consistency.
- **Documentation:** Update documentation and comments as necessary.
- **Testing:** Add or update tests to cover your changes.
- **Commit Messages:** Write clear and descriptive commit messages.

## License

This project is licensed under the [MIT License](LICENSE). You are free to use, modify, and distribute this software under the terms of the license.

## Contact

For any questions, suggestions, or issues, please open an [issue](https://github.com/yourusername/automata/issues) on the GitHub repository or contact the maintainer at [your.email@example.com](mailto:your.email@example.com).

