// Circular Doubly Linked List 
/*
Lab 4
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(string name) : name(name), next(nullptr), prev(nullptr) {}
};

struct CircularDoublyLinkedList {
private:
    Node* first;  // Instead of head
    Node* last;   // Instead of tail

public:
    CircularDoublyLinkedList(Node& initialNode) {
        first = new Node(initialNode.name);
        last = first;
        first->next = first;
        first->prev = first;
        cout << "Added first node: " << initialNode.name << endl;
    }

    ~CircularDoublyLinkedList() {
        if (first == nullptr) return;
        
        Node* current = first;
        do {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != first);
    }

    void add_node(Node& newNode) {
        Node* newPtr = new Node(newNode.name);
        newPtr->prev = last;
        newPtr->next = first;
        last->next = newPtr;
        first->prev = newPtr;
        last = newPtr;
        cout << "Added node: " << newNode.name << endl;
    }

    void display_forward() {
        if (first == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = first;
        string firstName = first->name;
        cout << "\nCircular Doubly Linked List (Forward):\n";
        do {
            cout << "[" << current->name << "]";
            if (current->next != first) {
                cout << " <-> ";
            }
            current = current->next;
        } while (current != first);
        cout << " <-> [" << firstName << "](cycle continues)\n";
    }

    void display_backward() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = last;
        string lastName = last->name;
        cout << "\nCircular Doubly Linked List (Backward):\n";
        do {
            cout << "[" << current->name << "]";
            if (current->prev != last) {
                cout << " <-> ";
            }
            current = current->prev;
        } while (current != last);
        cout << " <-> [" << lastName << "](cycle continues)\n";
    }

    void delete_by_name(string targetName) {
        if (first == nullptr) {
            cout << "Cannot delete. List is empty.\n";
            return;
        }

        Node* current = first;
        do {
            if (current->name == targetName) break;
            current = current->next;
        } while (current != first);

        if (current->name != targetName) {
            cout << "Node \"" << targetName << "\" not found.\n";
            return;
        }

        if (current == first && current == last) {
            first = nullptr;
            last = nullptr;
        }
        else if (current == first) {
            first = current->next;
            first->prev = last;
            last->next = first;
        }
        else if (current == last) {
            last = current->prev;
            last->next = first;
            first->prev = last;
        }
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        cout << "Deleted node: " << targetName << endl;
        delete current;
    }
};

int main() {
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Abu");

    CircularDoublyLinkedList list(node1);
    list.add_node(node2);
    list.add_node(node3);

    list.display_forward();
    list.display_backward();

    cout << "\nDeleting 'Ahmed'...\n";
    list.delete_by_name("Ahmed");
    list.display_forward();
    
    cout << "\nDeleting non-existent 'Aina'...\n";
    list.delete_by_name("Aina");

    cout << "\nAdding 'Lina'...\n";
    Node node4("Lina");
    list.add_node(node4);
    list.display_forward();

   

    return 0;
}
