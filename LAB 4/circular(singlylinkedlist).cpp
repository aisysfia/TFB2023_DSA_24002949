// Singly Linked List (Circular)

/*
Lab 4
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

// Circular LinkedList struct
struct CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    CircularLinkedList(Node& firstNode) {
        head = new Node(firstNode.name);
        head->next = head; // Point to itself to make it circular
        tail = head;
        cout << "Added first node: " << firstNode.name << endl;
    }

    // Add a new node to the end
    void add_element(Node& newNode) {
        Node* newNodePtr = new Node(newNode.name);
        newNodePtr->next = head; // New node points back to head
        tail->next = newNodePtr;
        tail = newNodePtr;
        cout << "Added node: " << newNode.name << endl;
    }

    // Display the list
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        string firstName = head->name; // Store the first node's name
        cout << "\n--- Circular Linked List ---\n";
        do {
            cout << "[" << current->name << "]";
            if (current->next != head) {
                cout << " -> ";
            }
            current = current->next;
        } while (current != head);
        cout << " -> [" << firstName << "](cycle continues)\n";
    }

    // Delete a node by name
    void delete_by_name(string targetName) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* current = head;
        Node* prev = tail; // In circular list, previous of head is tail

        do {
            if (current->name == targetName) {
                if (current == head) {
                    head = head->next;
                    tail->next = head; // Update tail's next to new head
                    if (current == tail) { // Only one node case
                        head = nullptr;
                        tail = nullptr;
                    }
                } else {
                    prev->next = current->next;
                    if (current == tail) {
                        tail = prev;
                    }
                }

                delete current;
                cout << "Deleted node: " << targetName << endl;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Node with name \"" << targetName << "\" not found.\n";
    }

    // Destructor to clean up memory
    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        Node* current = head;
        Node* nextNode;
        
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }
};

// Main function
int main() {
    // Step 1: Create initial nodes
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Abu");

    // Step 2: Create circular linked list and add nodes
    CircularLinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    // Step 3: Display list
    linkedlst.display_list();

    // Step 4: Delete a valid name
    cout << "\nDeleting 'Ali'...\n";
    linkedlst.delete_by_name("Ali");

    // Step 5: Display list again
    linkedlst.display_list();

    // Step 6: Try deleting a name that doesn't exist
    cout << "\nDeleting 'Aina' (not in list)...\n";
    linkedlst.delete_by_name("Aina");

    // Step 7: Add a new node after deletion
    cout << "\nAdding new node 'Lina'...\n";
    Node newNode("Lina");
    linkedlst.add_element(newNode);

    // Step 8: Final display
    linkedlst.display_list();

    return 0;
}
