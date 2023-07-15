#include <iostream>
#include <stack>
#include <string>

// Define the ExpressionManager class
class ExpressionManager {
public:
    // Method to check if the parentheses in the expression are balanced
    bool checkBalance(const std::string& expression);

    // Method to convert an infix expression to a postfix expression
    std::string infixToPostfix(const std::string& infix);

    // Method to evaluate a postfix expression and return the result
    int evaluatePostfix(const std::string& postfix);

private:
    // Helper method to check if a character is an operator
    bool isOperator(char c);

    // Helper method to determine the precedence of an operator
    int precedence(char c);
};


