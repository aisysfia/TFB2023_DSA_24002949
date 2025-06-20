// Singly Linked List
/*
Lab 3
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

// LinkedList struct
struct LinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    LinkedList(Node& firstNode) {
        head = new Node(firstNode.name);
        tail = head;
        cout << "Added first node: " << firstNode.name << endl;
    }

    // Add a new node to the end
    void add_element(Node& newNode) {
        Node* newNodePtr = new Node(newNode.name);
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
        cout << "\n--- Linked List ---\n";
        while (current != nullptr) {
            cout << "[" << current->name << "]";
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " -> NULL\n";
    }

    // Delete a node by name (without using prev pointer)
    void delete_by_name(string targetName) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        // Special case: deleting the head node
        if (head->name == targetName) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node: " << targetName << endl;
            if (head == nullptr) tail = nullptr;
            return;
        }

        // Find the node before the target node
        Node* beforeTarget = head;
        while (beforeTarget->next != nullptr && beforeTarget->next->name != targetName) {
            beforeTarget = beforeTarget->next;
        }

        // Check if we found the node to delete
        if (beforeTarget->next == nullptr) {
            cout << "Node with name \"" << targetName << "\" not found.\n";
            return;
        }

        Node* toDelete = beforeTarget->next;
        beforeTarget->next = toDelete->next;
        
        // Update tail if we're deleting the last node
        if (toDelete == tail) {
            tail = beforeTarget;
        }
        
        delete toDelete;
        cout << "Deleted node: " << targetName << endl;
    }

    // Destructor to clean up memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Main function
int main() {
    // Step 1: Create initial nodes
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Abu");

    // Step 2: Create linked list and add nodes
    LinkedList linkedlst(node1);
    linkedlst.add_element(node2);
    linkedlst.add_element(node3);

    // Step 3: Display list
    linkedlst.display_list();

    // Step 4: Delete a valid name
    cout << "\nDeleting 'Ahmed'...\n";
    linkedlst.delete_by_name("Ahmed");

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
