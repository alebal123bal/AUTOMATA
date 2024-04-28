#include <string>
#include <stack>
#include <vector>

#include "parenthesis.hpp"
#include "tree_splitter.hpp"

std::vector<Parenthesis> get_parentheses(const std::string& expression) {
    std::vector<Parenthesis> pairs;
    std::stack<int> stack;

    for (int i = 0; i < expression.length(); ++i) {
        char c = expression[i];
        if (c == '(') {
            // Push the index of '(' onto the stack
            stack.push(i);
        } else if (c == ')') {
            if (!stack.empty()) {
                // Pop the stack and create a new Parenthesis with the start and end indices
                int start = stack.top();
                stack.pop();
                pairs.push_back(Parenthesis(start, i));
            }
        }
    }

    return pairs;
}