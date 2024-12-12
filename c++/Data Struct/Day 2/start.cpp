#include <iostream>
using namespace std;

int main() {
int *p=new int[7];
int *head=p;

  //fill it
 for(int i=0;i<7;i++)
      p[i]=rand()%10;

  for(int i=0;i<7;i++)
    { *p=rand()%10;
      p++;     
    }//p????
  //p=-7;
  p=head;

  //compute avg
  float avg;
  for(int i=0;i<7;i++)
    { cout <<*p<<endl;
      avg+=*p; // avg+=*p; p++
      p++;
    }
  cout << "the average is "<<avg/7 <<endl;

  delete []p;

  float a = 3.123456789123456;
  double b=a;
  cout << a << endl; 
  cout << b << endl;
  
  
}