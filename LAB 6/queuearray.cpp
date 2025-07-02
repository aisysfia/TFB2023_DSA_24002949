// Queue using Array : Enqueue and Dequeue
/*
Lab 6
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // Maximum size of the queue

struct Queue {
private:
    string data[MAX_SIZE];  // Array to store queue elements
    int front;              // Index of front element
    int rear;               // Index of last element

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Enqueue operation (add element)
    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        data[rear] = name;
        cout << "Enqueued: " << name << endl;
    }

    // Dequeue operation (remove element)
    void dequeue() {
        if (isEmpty()) {
            cout << "\nQueue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << data[front] << endl;
        front++;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }

        cout << "\n--- Queue ---\n";
        for (int i = front; i <= rear; i++) {
            cout << "[" << data[i] << "]";
            if (i != rear) {
                cout << " <- ";
            }
        }
        cout << " <- NULL\n";
    }
};

// Main function
int main() {
    Queue q;

    // Enqueue some names
    q.enqueue("Ali");
    q.enqueue("Ahmed");
    q.enqueue("Abu");

    // Display the queue
    q.display();

    // Dequeue one element
    q.dequeue();

    // Display the queue again
    q.display();

    // Add more
    q.enqueue("Lina");

    // Final display
    q.display();
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
   
    return 0;
}
