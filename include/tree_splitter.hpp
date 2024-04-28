#ifndef TREESPLITTER_H
#define TREESPLITTER_H

#include <string>
#include <utility>
#include <vector>

#include "parenthesis.hpp"


/**
 * Finds and returns pairs of indices corresponding to matched parentheses in a given expression.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of Parenthesis, where each one has the indices of a matching '(' and ')' in the expression.
 */
std::vector<Parenthesis> get_parentheses(const std::string& expression);


/**
 * Finds and returns the depth of each operation, paired with its priority.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of pairs, where each pair consists of the operation depth and the operation priority.
 */
//TODO: Create a class for Operations with position and priority
std::vector<std::pair<int, int>> get_operation_status(const std::string& expression);

#endif  //TREESPLITTER_H