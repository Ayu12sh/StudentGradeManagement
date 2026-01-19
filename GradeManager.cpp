#include <iostream>
#include <iomanip>
#include "GradeManager.h"

using namespace std;

void inputStudentData(string names[], double grades[], char letters[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "\nEnter student " << i + 1 << " name: ";
        getline(cin, names[i]);

        do {
            cout << "Enter grade for " << names[i] << " (0-100): ";
            cin >> grades[i];
        } while (grades[i] < 0 || grades[i] > 100);

        letters[i] = getLetterGrade(grades[i]);
        cin.ignore();
    }
}

double calculateAverage(double grades[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}

double findHighestGrade(double grades[], int count, int &index) {
    double highest = grades[0];
    index = 0;
    for (int i = 1; i < count; i++) {
        if (grades[i] > highest) {
            highest = grades[i];
            index = i;
        }
    }
    return highest;
}

double findLowestGrade(double grades[], int count, int &index) {
    double lowest = grades[0];
    index = 0;
    for (int i = 1; i < count; i++) {
        if (grades[i] < lowest) {
            lowest = grades[i];
            index = i;
        }
    }
    return lowest;
}

char getLetterGrade(double grade) {
    if (grade >= A_MIN) return 'A';
    else if (grade >= B_MIN) return 'B';
    else if (grade >= C_MIN) return 'C';
    else if (grade >= D_MIN) return 'D';
    else return 'F';
}

void displayReport(string names[], double grades[], char letters[], int count) {
    cout << "\n=== Grade Report ===\n";
    cout << left << setw(22) << "Name"
         << setw(10) << "Grade"
         << "Letter\n";
    cout << "----------------------------------------\n";

    cout << fixed << setprecision(2);
    for (int i = 0; i < count; i++) {
        cout << left << setw(22) << names[i]
             << setw(10) << grades[i]
             << letters[i] << endl;
    }
}

int searchStudent(string names[], int count, string target) {
    for (int i = 0; i < count; i++) {
        if (names[i] == target) {
            return i;
        }
    }
    return -1;
}
