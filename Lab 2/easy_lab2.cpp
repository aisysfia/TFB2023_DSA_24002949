// Check if an array is subset of another array (easy)

/* Lab 2
Name : Nur Aisya Sofia
ID : 24002949 */


#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int a[], int m, int b[], int n) {
    // Create a hash set for all elements in a
    unordered_set<int> elements;
    for (int i = 0; i < m; i++) {
        elements.insert(a[i]);
    }

    // Check if all elements of b exist in the set
    for (int i = 0; i < n; i++) {
        if (elements.find(b[i]) == elements.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // Example 1: b is a subset of a (should return true)
    int a1[] = { 8, 19, 4, 73, 86, 2 };
    int m1 = sizeof(a1) / sizeof(a1[0]);
    int b1[] = { 4, 86, 19, 2 };
    int n1 = sizeof(b1) / sizeof(b1[0]);
    cout << "Example 1: " << (isSubset(a1, m1, b1, n1) ? "True" : "False") << endl;

    // Example 2: b is not a subset of a (should return false)
    int a2[] = { 2, 10, 8, 6, 12, 24 };
    int m2 = sizeof(a2) / sizeof(a2[0]);
    int b2[] = { 13, 8, 24 };
    int n2 = sizeof(b2) / sizeof(b2[0]);
    cout << "Example 2: " << (isSubset(a2, m2, b2, n2) ? "True" : "False") << endl;

    return 0;
}
