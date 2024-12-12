#include "Student1430.h"

Student1430::Student1430() {
   firstName = "";
   lastName = "";
   for(int i=0; i<4; i++)
      exams[i] = 0;
   average = 0;
}

Student1430::Student1430(string f, string l, int e[]) {
   firstName = f;
   lastName = l;
   for(int i=0; i<4; i++)
      exams[i] = e[i];
   updateAverage();
}

void Student1430::setFirstName(string f) {
   firstName = f;
}

void Student1430::setLastName(string l) {
   lastName = l;
}

void Student1430::setExamGrade(int grade, int pos) {
   exams[pos-1] = grade;
}

void Student1430::updateAverage() { 
   double temp = 0; 
   
   for(int i=0; i<4; i++)
      temp += exams[i];
      
   average = temp/4;
}

string Student1430::getFirstName() { return firstName; }
string Student1430::getLastName() { return lastName; }

double Student1430::getAverage() { 
   updateAverage();
   return average; 
}

string Student1430::finalGrade() { 
   updateAverage();
   
   if(average >= 90)
      return "A";
   else if(average < 90 && average >= 80)
      return "B";
   else if(average < 80 && average >= 70)
      return "C";
   else if(average < 70 && average >= 60)
      return "D";
   else return "F";
}
