#ifndef FUNCTIONSH
#define FUNCTIONSH

#include <iostream>
#include <iomanip>

using namespace std;


void readGrades(int grades[], const int nGrades)
{
    for(int i = 0; i < nGrades; i++) 
    {
      cin >> grades[i];
    }
}

double calculateAverage(const int grades[], const int nGrades)
{
    int total = 0;
    for(int i = 0; i < nGrades; i++) 
    {
        total += grades[i];
    }
    double avg = total / nGrades;
    return avg;
}

int nStudentsWithAPassingGrade(const int grades[],const int nGrades)
{
   return i;
    
}

#endif