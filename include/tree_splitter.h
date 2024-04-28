#ifndef TREESPLITTER_H
#define TREESPLITTER_H

#include <string>
#include <utility>
#include <vector>

#include "parenthesis.hpp"
#include "operation.hpp"
#include "expr_parser.hpp"


/**
 * Returns the dominant operation out of the given vector, i.e. it will be the breakpoint
 * to subdivide the expressio and populate the binary tree
 *
 * @param o The std::vector<Operation>& containing all the found Operations.
 * @return <start, end> where to break the expression
 */
std::pair<int, int> get_dominant_op(const std::vector<Operation>& o);

#endif  //TREESPLITTER_H