#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include <utility>
#include <iostream>

class Parenthesis {
private:
    std::pair<int, int> position;

public:
    Parenthesis();
    Parenthesis(int start, int end);
    std::pair<int, int> getPosition() const;
    void setPosition(int start, int end);
    void display() const;
};

#endif // PARENTHESIS_H