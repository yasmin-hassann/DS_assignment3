#include <list>
#include <iostream>

class Queue {
private:
    std::list<int> elements; // We are using list to make the queue dynamic

public:
    Queue(); // Constructor
    void enqueue(int data); // Add an element to the back of the queue
    int dequeue(); // Remove an element from the front of the queue and return it
    int front(); // Return the front element without removing it
    int size(); // Return the total number of elements in the queue
    void display(); // Display all elements in the queue
    bool isEmpty(); // Check if the queue is empty
};

