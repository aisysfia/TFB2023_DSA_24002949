// Breadth First Search (BFS)
/*
Lab 9 
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    const int n = 5; // Number of vertices: A-E
    int adj[n][n] = {
        // A  B  C  D  E
        { 0, 1, 1, 1, 0 }, // A
        { 1, 0, 0, 1, 1 }, // B
        { 1, 0, 0, 1, 0 }, // C
        { 1, 1, 1, 0, 1 }, // D
        { 0, 1, 0, 1, 0 }  // E
    };

    vector<bool> visited(n, false);
    queue<int> q;

    int start = 0; // Starting from A (index 0)
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Convert index back to character A–E
        char nodeChar = 'A' + current;
        cout << nodeChar << " ";

        // Check all neighbors
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
    return 0;
}

