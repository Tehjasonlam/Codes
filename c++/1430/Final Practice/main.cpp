#include <iostream>
using namespace std;

int main()
{  
   int n, d;  
   cin >> n >> d;  
   try 
   {        
      if (d <=0)   throw n;        
      int result = n/d; 
   } 
   catch(float e)  
   {     
      cout << "Exception 1" << endl;
   }  
   catch(double e)  
   {     
      cout << "Exception 2" << endl; 
   }  
   catch(...)  
   {     
      cout << "Unknown exception!" << endl; 
   }      
   return 0;
}