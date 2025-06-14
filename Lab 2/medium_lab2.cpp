// Rotate a Matrix by 180 degree (Medium) 

/* Lab 2
Name : Nur Aisya Sofia
ID : 24002949 */


#include <iostream>
using namespace std;

// Function to rotate the matrix by 180 degrees
void rotate180(int matrix[][100], int n) {
    // First reverse all rows
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }

    // Then reverse the order of rows
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        for (int k = 0; k < n; k++) {
            swap(matrix[i][k], matrix[j][k]);
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    int matrix[100][100];

    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, n);

    rotate180(matrix, n);

    cout << "\nMatrix after 180 degree rotation:\n";
    printMatrix(matrix, n);

    return 0;
}
