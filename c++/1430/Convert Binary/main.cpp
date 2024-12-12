#include <iostream>
using namespace std;

/* Define your functions here */ 

string IntToReverseBinary(int integerValue)
{
   string binaryDigits = "";
   while(integerValue > 0)
   {
      if(integerValue % 2 == 0)
      {
        binaryDigits += "0";
      }
      else
      {
        binaryDigits += "1";
      }
      integerValue /= 2;
   }
   return binaryDigits;
}
string StringReverse(string userString)
{
    string reverseString = "";
    for (int i = userString.size()-1; i >= 0 ; i--)
    {
        reverseString += userString[i];
    }
    return reverseString;

}
int main() {
   /* Type your code here. 
      Your code must call IntToReverseBinary() to get
      the binary string of an integer in a reverse order.
      Then call StringReverse() to reverse the string 
      returned from IntToReverseBinary().*/
    int inputVal;
    string binaryString;
    string revString;
    cout << "Enter Number: ";
    cin >> inputVal;

    binaryString = IntToReverseBinary(inputVal);
    revString = StringReverse(binaryString);
    
    cout << revString << endl;



   return 0;
}
