// Binary Search Tree
/*
Lab 8 
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    void insert(string name) {
        root = insertRecursive(root, name);
    }

private:
    Node* insertRecursive(Node* current, string name) {
        if (current == nullptr) {
            return new Node(name);
        }

        if (name < current->name) {
            current->left = insertRecursive(current->left, name);
        } else if (name > current->name) {
            current->right = insertRecursive(current->right, name);
        }
        // If name == current->name, do not insert duplicates
        return current;
    }
};

int main() {
    Tree tree;

    tree.insert("D");
    tree.insert("B");
    tree.insert("A");
    tree.insert("C");
    tree.insert("F");
    tree.insert("E");
    tree.insert("G");

    cout << "Root: " << tree.root->name << endl;
    cout << "Left child of root: " << tree.root->left->name << endl;
    cout << "Right child of root: " << tree.root->right->name << endl;
    cout << "Left child of B: " << tree.root->left->left->name << endl;
    cout << "Right child of B: " << tree.root->left->right->name << endl;
    cout << "Left child of F: " << tree.root->right->left->name << endl;
    cout << "Right child of F: " << tree.root->right->right->name << endl;

    return 0;
}
