#include <iostream>
//Please debug with the button at the bottom 
#include "automata.hpp"

// Define the global variable
std::string expression = "((3 * x**2 - 2 * x * y + y) / ((x - y)**2)) / "
                         "((2 * x / (y - x) - 3 * x**3)) + "
                         "((x + y)**3 / (4 * x**2 - 4 * y**2)) * "
                         "((1 / x + 1 / y)**2)";

int main() {
    // Print the string
    expression = strip_whitespace(expression);
    std::cout << "The expression is: \n" << expression << std::endl;
    std::vector<Parenthesis> p = get_parentheses(expression);

    return 0;
}