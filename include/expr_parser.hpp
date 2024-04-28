#ifndef TREESPLITTER_H
#define TREESPLITTER_H

#include <string>
#include <utility>
#include <vector>

#include "parenthesis.hpp"
#include "operation.hpp"


/**
 * Strips all whitespaces in a given expression.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return Same expression without spaces.
 */
std::string strip_whitespace(const std::string& expression);

/**
 * Finds and returns pairs of indices corresponding to matched parentheses in a given expression.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of Parenthesis, where each one has the indices of a matching '(' and ')' in the expression.
 */
std::vector<Parenthesis> get_parentheses(const std::string& expression);


/**
 * Finds and returns each operation position, depth and priority.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of Operation, containing operation <start, end>, depth and operation priority.
 */
std::vector<Operation> get_operations(const std::string& expression);

/**
 * Converts an operation char into its priority: 
 * 0 for '+', ',' 
 * 1 for '*', '/' 
 *
 * @param c The char of the operation.
 * @return Integer priority.
 */
int char_to_priority(const char c);

#endif  //TREESPLITTER_H