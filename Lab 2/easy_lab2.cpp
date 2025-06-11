#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool isSubset(const vector<int>& a, const vector<int>& b) {
    // Create a hash set for all elements in a
    unordered_set<int> elements(a.begin(), a.end());

    // Check if all elements of b exist in the set
    for (int num : b) {
        if (elements.find(num) == elements.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    // Example 1: b is a subset of a (should return true)
    vector<int> a1 = { 8, 19, 4, 73, 86, 2 };
    vector<int> b1 = { 4, 86, 19, 2 };
    cout << "Example 1: " << (isSubset(a1, b1) ? "True" : "False") << endl;

    // Example 2: b is not a subset of a (should return false)
    vector<int> a2 = { 2, 10, 8, 6, 12, 24 };
    vector<int> b2 = { 13, 8, 24 };
    cout << "Example 2: " << (isSubset(a2, b2) ? "True" : "False") << endl;

    return 0;
}
