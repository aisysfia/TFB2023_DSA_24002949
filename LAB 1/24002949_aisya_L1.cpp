/*
Lab 1
Name : Nur Aisya Sofia
ID : 24002949 
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Student {
    int id;
    string name;
    string phone;
    string email;
};

int main() {
    const int MAX_STUDENTS = 10;
    Student students[MAX_STUDENTS];
    int numStudents;

    cout << "Enter number of students (max " << MAX_STUDENTS << "): ";
    if (!(cin >> numStudents)) {
        cout << "Invalid input. Exiting program.\n";
        return 1;
    }

    // Input validation
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        cout << "Invalid number of students. Exiting program.\n";
        return 1;
    }

    cin.ignore(); // Clear the newline character

    for (int i = 0; i < numStudents; i++) {
        cout << "\nEnter details for student #" << i + 1 << ":\n";

        // Input ID
        cout << "ID: ";
        if (!(cin >> students[i].id)) {
            cout << "Invalid ID. Exiting program.\n";
            return 1;
        }

        cin.ignore(); // Clear the input buffer

        // Input Name
        cout << "Name: ";
        if (!getline(cin, students[i].name)) {
            cout << "Input error. Exiting program.\n";
            return 1;
        }

        // Input Phone
        cout << "Phone: ";
        if (!getline(cin, students[i].phone)) {
            cout << "Input error. Exiting program.\n";
            return 1;
        }

        // Input Email
        cout << "Email: ";
        if (!getline(cin, students[i].email)) {
            cout << "Input error. Exiting program.\n";
            return 1;
        }
    }
    
    cout << "\n\n--- Student Records ---\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "\nStudent #" << i + 1 << ":\n";
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Phone: " << students[i].phone << endl;
        cout << "Email: " << students[i].email << endl;
    }
    
   // Display Student Records
   /*
   Student #1
   ID: 242000
   Name: Ewanina
   Phone: 0123456789
   Email: ewanina_242000@utp.edu.my
   */

    return 0;
}
