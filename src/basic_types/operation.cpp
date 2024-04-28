#include "operation.hpp"

// Default constructor
Operation::Operation() {
    position = std::make_pair(0, 0);
}

// Constructor that initializes the position with start and end indices, as well as depth and priority
Operation::Operation(int start, int end, int depth, int priority, std::string value)
    : position(std::make_pair(start, end)), depth(depth), priority(priority), value(value) {}

// Getter for the position
std::pair<int, int> Operation::getPosition() const {
    return position;
}

// Setter for the position
void Operation::setPosition(int start, int end) {
    position.first = start;
    position.second = end;
}

// Getter for the depth
int Operation::getDepth() const {
    return depth;
}

// Setter for the depth
void Operation::setDepth(int newDepth) {
    depth = newDepth;
}

// Getter for the priority
int Operation::getPriority() const {
    return priority;
}

// Setter for the priority
void Operation::setPriority(int newPriority) {
    priority = newPriority;
}

// Getter for the value
std::string Operation::getValue() const {
    return value;
}

// Setter for the value
void Operation::setValue(std::string newValue) {
    value = newValue;
}

// A method to display the position of the Operation pair
void Operation::display() const {
    std::cout << "Operation starts at: " << position.first
              << " and ends at: " << position.second
              << " with a depth of: " << depth
              << " and a priority of: " << priority
              << " and a value of: " << value
               << std::endl;
}