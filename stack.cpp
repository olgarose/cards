// Implementation file for the Stack class
#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{
    stackSize = 0;
    stackArray = new int[stackSize];
}

Stack::Stack(const Stack& right)
{
    // hard copy array
    if (this != &right)
    {
        stackSize = right.stackSize;
        stackArray = new int[stackSize];
        for (int i = 0; i < stackSize; i++)
            stackArray[i] = right.stackArray[i];
    }
}

Stack::~Stack()
{
    delete [] stackArray;
    stackSize = 0;
}

void Stack::push(int num)
{
    // Increment the stacksize
    stackSize++;
    
    // Dynamically allocate new array of the proper size
    int* tempArray = new int[stackSize];
    
    // add the number being pushed to the previous stack
    stackArray[stackSize] = num;
    
    
    // copy all the array elements from the previous stack to the new larger one
    for (int i = 0; i <= stackSize; i++){
        tempArray[i] = stackArray[i];
    }
    
    // deallocate the memory for the previoius array
    delete stackArray;
    
    // make the array point to the new array
    stackArray = tempArray;
}

bool Stack::pop(int &num)
{
    bool pop; // to return whether a value was successfully popped to main
    
    if (isEmpty())
    {
        pop = false;
    }
    else
    {
        
        num = stackArray[stackSize];
        stackSize--;
        
        // Dynamically allocate new array of the proper size
        int* tempArray = new int[stackSize];
        
        // add the number being pushed to the previous stack
        //stackArray[stackSize] = num;
        
        
        // copy all the array elements from the previous stack to the new larger one
        for (int i = 0; i <= stackSize; i++){
            tempArray[i] = stackArray[i];
        }
        
        // deallocate the memory for the previoius array
        delete stackArray;
        
        // make the array point to the new array
        stackArray = tempArray;
        pop = true;
    }
    return pop;
}


bool Stack::isEmpty() const
{
    bool status;
    
    if (stackSize == 0)
        status = true;
    else
        status = false;
    
    return status;
}

Stack& Stack::operator=(const Stack &right)
{
    
    if( this != &right){
        stackSize = right.stackSize;
        stackArray = new int[stackSize];
        for (int i = 0; i < stackSize; i++)
            stackArray[i] = right.stackArray[i];
    }
    return *this;
}


