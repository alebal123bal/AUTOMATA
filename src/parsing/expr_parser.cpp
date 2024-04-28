#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <cctype>

#include "parenthesis.hpp"
#include "operation.hpp"
#include "expr_parser.hpp"

std::string strip_whitespace(const std::string& expression) {
    std::string result;
    result.reserve(expression.length());  // Reserve space to avoid multiple reallocations

    // Copy non-whitespace characters from the expression to result
    std::copy_if(expression.begin(), expression.end(), std::back_inserter(result),
                 [](unsigned char c) { return !std::isspace(c); });

    return result;
}

std::vector<Parenthesis> get_parentheses(const std::string& expression) {
    std::vector<Parenthesis> parentheses_vec;
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
                parentheses_vec.push_back(Parenthesis(start, i));
            }
        }
    }

    return parentheses_vec;
}


std::vector<Operation> get_operations(const std::string& expression) {
    std::vector<Operation> operation_vec;

    int curr_start = 0;
    int curr_end = 0;
    int curr_depth = 0;
    int curr_prio = 0;

    //Variable to get all consequent operations
    bool lock_sequence = false;

    for (int i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (c == '+' or c == '-' or c == '*' or c == '/') {
            // Check if an operations sequence was pending
            if(lock_sequence == false){
                curr_start = i;
                lock_sequence = true;
            }
            else{
                //Check if the current priority is different than the old: case of e.g. 5*-R1
                if (curr_prio != char_to_priority(c)){
                    // End the operations sequence
                    curr_end = i-1;
                    // Create Operation object
                    operation_vec.push_back(Operation(curr_start, curr_end, curr_depth, curr_prio));
                    // Update current selection
                    curr_start = i;
                    curr_prio = char_to_priority(c);
                    // Keep the lock
                } 
            }
        }
        else{
            if (c == '(') {
                // Increase depth by 1
                curr_depth++;
            } else if (c == ')') {
                // Increase depth by 1
                curr_depth--;
            }

            // CHekc if an operation sequence was pending
            if(lock_sequence == true){
                // Release the lock
                lock_sequence = false;
                // End the operations sequence
                curr_end = i-1;
                // Create Operation object
                operation_vec.push_back(Operation(curr_start, curr_end, curr_depth, curr_prio));
            }
        }
    }

    return operation_vec;
}

int char_to_priority(char c){
    if (c == '+' or c == '-'){
        return 0;
    }
    else if (c == '*' or c == '/')
    {
        return 1;
    }
    else{
        return -1;  //Should never get here
    }
    
}