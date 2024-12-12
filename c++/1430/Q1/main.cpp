#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    const int MAXNGRADES = 100;
    int nGrades;
    cin >> nGrades;
    int grades[MAXNGRADES];
    readGrades(grades,nGrades);
    cout << "Average: " << fixed << setprecision(1) << calculateAverage(grades,nGrades) << endl;
    cout << "Number of students with a passing grade: " << nStudentsWithAPassingGrade(grades,nGrades) << endl;
    return 0;   
}
