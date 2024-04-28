#include "parenthesis.hpp"

// Default constructor
Parenthesis::Parenthesis() {
    position = std::make_pair(0, 0);
}

// Constructor that initializes the position with start and end indices
Parenthesis::Parenthesis(int start, int end) {
    position = std::make_pair(start, end);
}

// Getter for the position
std::pair<int, int> Parenthesis::getPosition() const {
    return position;
}

// Setter for the position
void Parenthesis::setPosition(int start, int end) {
    position.first = start;
    position.second = end;
}

// A method to display the position of the parenthesis pair
void Parenthesis::display() const {
    std::cout << "Parenthesis starts at: " << position.first
              << " and ends at: " << position.second << std::endl;
}