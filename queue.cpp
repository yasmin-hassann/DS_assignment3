#include "queue.h"
#include <iostream>

// Constructor
Queue::Queue() {
    // Nothing to do here as list automatically initializes itself
}

// Add an element to the back of the queue
void Queue::enqueue(int data) {
    elements.push_back(data);
}

// Remove an element from the front of the queue and return it
int Queue::dequeue() {
    if (!this->isEmpty()) {
        int frontElement = elements.front(); // Store the front element
        elements.pop_front(); // Remove the front element
        return frontElement; // Return the stored element
    }
    else {
        std::cout << "Queue is empty. Cannot dequeue" << std::endl;
        return -1; // Return -1 to indicate an error
    }
}

// Return the front element without removing it
int Queue::front() {
    if (!this->isEmpty()) {
        return elements.front();
    }
    else {
        std::cout << "Queue is empty." << std::endl;
        return -1; // Return -1 to indicate an error
    }
}

// Display all elements in the queue
void Queue::display() {
    if (!this->isEmpty()) {
        for (const int& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Queue is empty." << std::endl;
    }
}

// Return the total number of elements in the queue
int Queue::size() {
    return elements.size();
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return elements.empty();
}
