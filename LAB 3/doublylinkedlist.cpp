#include <iostream>
#include <string>
using namespace std;

// Node struct for a doubly linked list
struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly linked list struct
struct DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize the list with the first node
    DoublyLinkedList(Node& firstNode) {
        head = new Node(firstNode.name);
        tail = head;
        cout << "Added first node: " << firstNode.name << endl;
    }

    // Operation 1: Add a node at the end
    void add_node(Node& newNode) {
        Node* newPtr = new Node(newNode.name);
        tail->next = newPtr;
        newPtr->prev = tail;
        tail = newPtr;
        cout << "Added node: " << newNode.name << endl;
    }

    // Operation 2: Display the list forward
    void display_list() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = head;
        cout << "\nCurrent Doubly Linked List:\n";
        while (current != nullptr) {
            cout << "[" << current->name << "]";
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << " -> NULL\n";
    }

    // Display list from tail to head
    void display_list_backward() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* current = tail;
        cout << "\nDoubly Linked List (Backward):\n";
        while (current != nullptr) {
            cout << "[" << current->name << "]";
            if (current->prev != nullptr) cout << " <-> ";
            current = current->prev;
        }
        cout << " -> NULL\n";
    }
    // Operation 3: Delete a node by name (value)
    void delete_by_name(string targetName) {
        if (head == nullptr) {
            cout << "Cannot delete. List is empty.\n";
            return;
        }

        Node* current = head;

        // Traverse to find the node
        while (current != nullptr && current->name != targetName) {
            current = current->next;
        }

        // If not found
        if (current == nullptr) {
            cout << "Node with name \"" << targetName << "\" not found.\n";
            return;
        }

        // Node is the head
        if (current == head) {
            head = current->next;
            if (head != nullptr)
                head->prev = nullptr;
            else
                tail = nullptr;  // List is now empty
        }
        // Node is the tail
        else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        }
        // Node is in the middle
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        cout << "Deleted node: " << targetName << endl;
        delete current;
    }
};

// Main function to demonstrate the operations
int main() {
    // Step 1: Create initial nodes
    Node node1("Ali");
    Node node2("Ahmed");
    Node node3("Abu");

    // Step 2: Create the doubly linked list with the first node
    DoublyLinkedList dlist(node1);

    // Step 3: Add more nodes
    dlist.add_node(node2);
    dlist.add_node(node3);

    // Step 4: Display the current list
    dlist.display_list();

    // Step 5: Delete a node by name
    cout << "\nDeleting node 'Ahmed'...\n";
    dlist.delete_by_name("Ahmed");

    // Step 6: Display after deletion
    dlist.display_list();

    // Step 7: Try deleting a non-existent node
    cout << "\nDeleting node 'Aina' (not in list)...\n";
    dlist.delete_by_name("Aina");

    // Step 8: Add a new node
    cout << "\nAdding new node 'Lina'...\n";
    Node newNode("Lina");
    dlist.add_node(newNode);

    // Step 9: Final display
    dlist.display_list();
    dlist.display_list_backward();

    return 0;
}
