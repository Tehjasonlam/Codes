#ifndef STUDENT1430_H
#define STUDENT1430_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student1430 {
private:
   string firstName;
   string lastName;
   int exams[4];
   double average;
   void updateAverage();
   
public:
   Student1430();
   Student1430(string f, string l, int e[]);
   void setFirstName(string f);
   void setLastName(string l);
   void setExamGrade(int grade, int pos);
   string getFirstName();
   string getLastName();
   double getAverage();
   string finalGrade();
};

#endif
