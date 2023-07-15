#include "ExpressionManager.h"

// Check if a character is an operator
bool ExpressionManager::isOperator(char c) {
    // If the character is +, -, *, /, or %, then it's an operator
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Get the precedence of an operator
int ExpressionManager::precedence(char c) {
    // Assign a higher precedence to * / %
    if (c == '*' || c == '/' || c == '%')
        return 2;
    // Assign a lower precedence to + -
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // For non-operator characters
}

// Check if the parentheses in an expression are balanced
bool ExpressionManager::checkBalance(const std::string& expression) {
    std::stack<char> s;
    for (char c : expression) {
        // Push opening parentheses onto the stack
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            // If the stack is empty or the top of the stack does not match the closing parenthesis, return false
            if (s.empty() || (c == ')' && s.top() != '(') || (c == '}' && s.top() != '{') || (c == ']' && s.top() != '['))
                return false;
            // Remove the opening parenthesis from the stack
            s.pop();
        }
    }
    // If the stack is empty, the parentheses are balanced
    return s.empty();
}

std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    std::stack<char> s;
    std::string postfix;
    for (char c : infix) {
        if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        else if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            // handle ')' and '}' and ']'
            while (!s.empty() && s.top() != '(' && s.top() != '{' && s.top() != '[') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty())
                s.pop();
        }
        else {
            postfix += c;
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


int ExpressionManager::evaluatePostfix(const std::string& expression)
{
    std::stack<int> stack;

    for (char ch : expression) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // push digit onto stack
        }
        else {
            if (stack.empty()) {
                std::cout << "Invalid postfix expression." << std::endl;
                return -1; // return error
            }
            int operand2 = stack.top();
            stack.pop();

            if (stack.empty()) {
                std::cout << "Invalid postfix expression." << std::endl;
                return -1; // return error
            }
            int operand1 = stack.top();
            stack.pop();

            switch (ch) {
            case '+': stack.push(operand1 + operand2); break;
            case '-': stack.push(operand1 - operand2); break;
            case '*': stack.push(operand1 * operand2); break;
            case '/':
                if (operand2 == 0) {
                    std::cout << "Invalid postfix expression: division by zero." << std::endl;
                    return -1; // return error
                }
                stack.push(operand1 / operand2);
                break;
            case '%': stack.push(operand1 % operand2); break;
            }
        }
    }

    if (stack.empty()) {
        std::cout << "Invalid postfix expression." << std::endl;
        return -1; // return error
    }

    return stack.top(); // result is on top of stack
}

