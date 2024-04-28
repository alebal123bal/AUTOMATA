#include <utility>
#include <iostream>

class Parenthesis {
private:
    std::pair<int, int> position;  // Holds the start and end positions of a parenthesis pair

public:
    // Default constructor
    Parenthesis() : position(0, 0) {}

    // Constructor that initializes the position with start and end indices
    Parenthesis(int start, int end) : position(start, end) {}

    // Getter for the position
    std::pair<int, int> getPosition() const {
        return position;
    }

    // Setter for the position
    void setPosition(int start, int end) {
        position.first = start;
        position.second = end;
    }

    // A method to display the position of the parenthesis pair
    void display() const {
        std::cout << "Parenthesis starts at: " << position.first
                  << " and ends at: " << position.second << std::endl;
    }
};