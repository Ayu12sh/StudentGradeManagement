#ifndef GRADEMANAGER_H
#define GRADEMANAGER_H

#include <string>
using namespace std;

// Constants
const int MAX_STUDENTS = 50;
const double A_MIN = 90.0;
const double B_MIN = 80.0;
const double C_MIN = 70.0;
const double D_MIN = 60.0;

// Function Declarations
void inputStudentData(string names[], double grades[], char letters[], int count);
double calculateAverage(double grades[], int count);
double findHighestGrade(double grades[], int count, int &index);
double findLowestGrade(double grades[], int count, int &index);
char getLetterGrade(double grade);
void displayReport(string names[], double grades[], char letters[], int count);
int searchStudent(string names[], int count, string target);

#endif
