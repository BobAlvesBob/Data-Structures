#include <iostream>
#include <string>
#include <cctype>

class Node {
public:
    char data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return '\0'; // Stack is empty
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (top == nullptr) {
            return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3; // Exponenciação tem a mais alta precedência
    }
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    Stack stack;
    std::string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

int main() {
    std::string infix;
    std::cout << "Enter an infix expression: ";
    std::getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}
