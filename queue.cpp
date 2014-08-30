#include "queue.h"
using namespace std;

Queue::Queue()
{
    // Set front and rear of que to be pointing at null
    front = nullptr;
    rear = nullptr;
    numElems = 0; // Number of elements are zero
    
}
void Queue::enqueue(int num)
{
    // Dynamically allocated node to store the number in the que
    node* newNode = nullptr;
    newNode = new node;
    newNode->value = num;
    newNode-> next = nullptr;
    
    // If the queue is empty the front and read now both point to the new node
    if (isEmpty()){
        front = newNode;
        rear = newNode;
    }
    else{ // otherwise the new ned is attached to the rear and then becomes
          // the new rear
        rear->next = newNode;
        rear = newNode;
    }
    numElems++; // increment the number of elements
}
bool Queue::dequeue(int& num)
{
    // returns true if dequeue was successful
    
    node* temp = nullptr;
    bool empty = true;
    
    // if queue is not empty
    if(!isEmpty()){
        num = front->value; // the num is the front value
        temp = front; // point temp to the front
        delete front;
        front = temp->next; // front is now point to the next value
        empty = false;
        numElems--;
    }
    else
        empty = true;
    
    
    return !empty;
}

bool Queue::isEmpty() const
{
    return (numElems <= 0);
}

void Queue::operator=(const Queue& right)
{
    if(this != &right){
        node* ptr = right.front;
        
        while(ptr != nullptr){
            enqueue(ptr->value); // while traversing right side, made a new
                                 // que using enque
            ptr = ptr->next;
        }
    }
}

Queue::Queue(const Queue& right)
{
    if(this != &right){
        node* ptr = right.front; // point to the front of the right
        
        while(ptr != nullptr){ // make a brand new list by enqueing the values
            enqueue(ptr->value);
            ptr = ptr->next;
        }
    }
}
Queue::~Queue()
{
    clear();
}
void Queue::clear()
{
    int value; // dummy variable to dequeue the que
    
    while(!isEmpty())
        dequeue(value);
}
