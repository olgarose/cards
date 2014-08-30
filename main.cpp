// Olga Rocheeva
// lab11.cpp
// Purpose: Demonstrates pushing and popping from stack. Pushes value beyond
// the stack size
// Input: integers
// Processing: stack pushing and popping
// Output: result of stack pushing and popping


#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

int main()
{
    int value;
    // char ans;
    Stack stack;
    int catchVar;
    
    for (int i = 0; i < 5; i++){
        cout << "Enter a value for the stack: ";
        cin >> value;
        stack.push(value);
    }
    
    if (stack.pop(catchVar))
        cout << "Popping from first: " << catchVar << endl;
    
    cout << "Copying first stack to second with copy constructor." << endl;
    Stack stack2(stack);
    
    
    if (stack2.pop(catchVar))
        cout << "Popping from second: " << catchVar << endl;
    
    if (stack2.pop(catchVar))
        cout << "Popping from second: " << catchVar << endl;
    
    cout << "Assigning second stack to third using overloaded = operator."
    << endl;
    
    Stack stack3 = stack2;
    
    if(stack3.pop(catchVar))
        cout << "Popping from third: " << catchVar << endl;
    
    for(int i = 0; i < 2; i++){
        if(stack3.pop(catchVar))
            cout << "Popping from third: " << catchVar << endl;
    }
    
    Queue queue, queue3;
    
    for (int i = 0; i < 5; i++){
        cout << "Enter a value for the que: ";
        cin >> value;
        queue.enqueue(value);
    }
    
    if(queue.dequeue(catchVar))
        cout << "Dequeue from first: " << catchVar << endl;
    
    if(queue.dequeue(catchVar))
        cout << "Dequeue from first: " << catchVar << endl;
    
    cout << "Making a second que with a copy constructor..." << endl;
    Queue queue2(queue);
    
    if(queue2.dequeue(catchVar)){
        cout << "Dequeue from second: " << catchVar << endl;
    }
    else{
        cout << "Que is empty." << endl;
    }
    
    cout << "Making a third que with an overloaded assignment operator..." << endl;
    queue3 = queue2;
    
    for (int i = 0; i< 3; i++){
        if (queue3.dequeue(catchVar)){
            cout << "Deque from third: " << catchVar << endl;
        }
        else{
            cout << "Que is empty." << endl;
        }
    }
    cout << endl;
}
