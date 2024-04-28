#ifndef OPERATION_H
#define OPERATION_H

#include <utility>
#include <iostream>

class Operation {
private:
    std::pair<int, int> position;
    int depth;
    int priority;
    // Add std::string expression

public:
    Operation();
    Operation(int start, int end, int depth, int priority);
    
    std::pair<int, int> getPosition() const;
    void setPosition(int start, int end);
    
    int getDepth() const;
    void setDepth(int depth);
    
    int getPriority() const; 
    void setPriority(int priority);

    void display() const;
};

#endif // OPERATION_H