// Maximum size rectangle binary sub-matrix with all 1s ( Hard )

/* Lab 2
Name : Nur Aisya Sofia
ID : 24002949 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the largest rectangle area in a histogram
int maxHistogramArea(vector<int>& heights) {
    int maxArea = 0;
    stack<int> s;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

// Function to find the maximum size rectangle of all 1's
int maxRectangle(vector<vector<int>>& mat) {
    if (mat.empty()) return 0;

    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> height(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        // Build histogram for this row
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1)
                height[j] += 1;
            else
                height[j] = 0;
        }
        // Calculate max area for current histogram
        maxArea = max(maxArea, maxHistogramArea(height));
    }

    return maxArea;
}

int main() {
    // Example input
    int rows = 4, cols = 4;
    vector<vector<int>> mat = {
        {0, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 0}
    };

    cout << "Input Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    int maxArea = maxRectangle(mat);
    cout << "\nMaximum size rectangle of 1's: " << maxArea << endl;

    return 0;
}
