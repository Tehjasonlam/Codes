#include <iostream>

using namespace std;

int main() {
   int array[6]; // Array of 6
   int *ptr = NULL; // makes the pointer = null
   
   for(int i = 0; i < 6; i++) // makes the loop go 6 times
      cin >> array[i]; //takes input and put in array
   
   //Assign pointer to head of array
   ptr = array;
   
   for(int i = 0; i < 6; i++) // Makes the loop go 6 times
   {
      if(*ptr % 2 == 0) // check if even
         cout << *ptr << " "; // print the even number
      ptr++; // goes to the next number
   }
   
   return 0;
}