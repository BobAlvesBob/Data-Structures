#include <iostream>
#include <string>

class Node {
public:
    char data;
    Node* next;
};

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == nullptr) {
            return -1; // Stack is empty
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

bool areParenthesesBalanced(const std::string& equation) {
    Stack stack;

    for (char ch : equation) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            if (stack.isEmpty()) {
                return false; // Closing parenthesis without a matching opening
            }
            stack.pop();
        }
    }

    return stack.isEmpty(); // If stack is not empty, there are unmatched opening parentheses
}

int main() {
    std::string equation;
    std::cout << "Enter an equation: ";
    std::getline(std::cin, equation);

    if (areParenthesesBalanced(equation)) {
        std::cout << "Parentheses are correctly balanced." << std::endl;
    } else {
        std::cout << "Parentheses are not balanced." << std::endl;
    }

    return 0;
}
