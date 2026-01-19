#include <iostream>
#include "GradeManager.h"

using namespace std;

int main() {
    string names[MAX_STUDENTS];
    double grades[MAX_STUDENTS];
    char letters[MAX_STUDENTS];

    int studentCount;
    int choice;

    cout << "=== Student Grade Management System ===\n\n";

    do {
        cout << "How many students? (1-50): ";
        cin >> studentCount;
    } while (studentCount < 1 || studentCount > MAX_STUDENTS);

    cin.ignore();
    inputStudentData(names, grades, letters, studentCount);

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Grade Report\n";
        cout << "2. Show Statistics\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayReport(names, grades, letters, studentCount);
                break;

            case 2: {
                int hi, lo;
                double avg = calculateAverage(grades, studentCount);
                double high = findHighestGrade(grades, studentCount, hi);
                double low = findLowestGrade(grades, studentCount, lo);

                cout << "\nClass Average: " << avg << endl;
                cout << "Highest Grade: " << high << " (" << names[hi] << ")\n";
                cout << "Lowest Grade: " << low << " (" << names[lo] << ")\n";
                break;
            }

            case 3: {
                string searchName;
                cout << "Enter student name: ";
                getline(cin, searchName);

                int index = searchStudent(names, studentCount, searchName);
                if (index != -1) {
                    cout << "Found: " << names[index]
                         << " - " << grades[index]
                         << " (" << letters[index] << ")\n";
                } else {
                    cout << "Student not found.\n";
                }
                break;
            }

            case 4:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
