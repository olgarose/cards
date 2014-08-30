// Specification file for the Stack class
#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int *stackArray;  // Pointer to the stack array
    int stackSize;    // The stack size
    
    void resizeSmaller();
    void resizeBigger();
    bool isFull() const;
    bool isEmpty() const;
    
    public:
    // Constructor
    Stack();
    
    // Copy constructor
    Stack(const Stack&);
    
    // Overloaded assignment operator
    Stack& operator=(const Stack &right);
    
    // Destructor
    ~Stack();
    
    // Stack operations
    void push(int);
    bool pop(int &);
};
#endif
