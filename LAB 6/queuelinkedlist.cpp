// Queue using Linked List : Enqueue and Dequeue
/*
Lab 6
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

// Queue struct using Linked List
struct Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue: Add a new element to the rear of the queue
    void enqueue(const string& name) {
        Node* newNode = new Node(name);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << name << endl;
    }

    // Dequeue: Remove an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->name << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Display the queue
    void display() {
        if (front == nullptr) {
            cout << "\nQueue is empty. Cannot dequeue.\n";
            return;
        }

        Node* current = front;
        cout << "\n--- Queue ---\n";
        while (current != nullptr) {
            cout << "[" << current->name << "]";
            if (current->next != nullptr)
                cout << " <- ";
            current = current->next;
        }
        cout << " <- NULL\n";
    }

    // Destructor to clean up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Abu");

    q.display();

    q.dequeue();

    q.display();

    q.enqueue("Lina");

    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue(); // should show queue is empty now

    q.display();

    return 0;
}
