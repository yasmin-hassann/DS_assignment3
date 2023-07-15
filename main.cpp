
//yasmin Hassan
#include "ExpressionManager.h"
#include "queue.h"
#include<iostream>
using namespace std;


int main() {
    ExpressionManager em;
    string expression;

    while (true) {
        // Prompt the user for an infix expression
        cout << "Enter an infix expression or 'quit' to exit the program: ";
        getline(std::cin, expression);

        // Check if the user wants to quit
        if (expression == "quit") {
            break;
        }

        // Check if the parentheses in the expression are balanced
        if (em.checkBalance(expression)) {
            // Convert the infix expression to postfix
            string postfix = em.infixToPostfix(expression);
            cout << "The postfix expression is: " << postfix;
            // Evaluate the postfix expression
            int result = em.evaluatePostfix(postfix);
            // Output the result
            std::cout << " = " << result << std::endl;
        }
        else {
            // If the parentheses are not balanced, output an error message
            cout << "The expression is invalid due to unbalanced parentheses." << std::endl;
        }
    }




    Queue queue; // Create a Queue object
    char ch;
    int choice, data;

    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Size\n5. Display all elements";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Enqueue operation
            cout << "\nEnter an integer number: ";
            cin >> data;
            queue.enqueue(data); // Enqueue the entered data
            cout << data << " has been enqueued ";
            break;

        case 2: // Dequeue operation
            if (!queue.isEmpty()) { // Check if the queue is not empty
                cout << "The data dequeued is : " << queue.dequeue() << "\n";
            }
            else {
                cout << "Queue is empty" << "\n";
            }
            break;

        case 3: // Front operation
            if (!queue.isEmpty()) { // Check if the queue is not empty
                cout << "Front of the queue is : " << queue.front() << "\n";
            }
            else {
                cout << "Queue is empty" << "\n";
            }
            break;

        case 4: // Size operation
            cout << "Size of queue is : " << queue.size() << "\n";
            break;

        case 5: // Display operation
            queue.display();
            break;

        default:
            cout << "An invalid choice!!!\n\n";
        }
        cout << "Do you want to continue? ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y'); // Continue asking for operations until user says no

    return 0;
}
