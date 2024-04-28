#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * Finds and returns pairs of indices corresponding to matched parentheses in a given expression.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of pairs, where each pair consists of the indices of a matching '(' and ')' in the expression.
 */
vector<pair<int, int>> get_parentheses_pair(const string& expression);


/**
 * Finds and returns the depth of each operation, paired with its priority.
 *
 * @param expression The string containing the mathematical or logical expression with parentheses.
 * @return A vector of pairs, where each pair consists of the operation depth and the operation priority.
 */
vector<pair<int, int>> get_operation_status(const string& expression);