// Stack using Linked List
/*
Lab 5 
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
#include <string>
using namespace std;

// Node struct
struct Node {
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

// Stack struct using linked list
struct Stack {
private:
    Node* top; // Top of the stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push (insert element on top)
    void push(const string& name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
        cout << "Pushed: " << name << endl;
    }

    // Pop (remove element from top)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        Node* temp = top;
        cout << "\nPopped: " << temp->name << endl;
        top = top->next;
        delete temp;
    }

    // Peek (view top element)
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "\nTop element: " << top->name << endl;
        }
    }

    // Display stack from top to bottom
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "\n--- Stack (Top to Bottom) ---\n";
        Node* current = top;
        while (current != nullptr) {
            cout << "[" << current->name << "]" << endl;
            current = current->next;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor to clean up memory
    ~Stack() {
    while (!isEmpty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

};

// Main function
int main() {
    Stack myStack;

    // Push elements
    myStack.push("Ali");
    myStack.push("Ahmed");
    myStack.push("Abu");

    // Display current stack
    myStack.display();

    // Peek at the top element
    myStack.peek();

    // Pop one element
    myStack.pop();

    // Peek again to see the new top
    myStack.peek();

    // Final display
    myStack.display();

    return 0;
}
