#include <iostream>
#include "glass.h"


int main()
{
   
   Glass myglass("Ceramic","Water");
   cout << "Content : ";
   cout << myglass.getContent()<<endl;
   cout << "Material : ";
   cout << myglass.getMaterial()<<endl;
   cout << "Full: ";
   
   if(myglass.isFull())
   {
      cout<<"True"<<endl;
   }
   else
   {
      cout<<"False"<<endl;
   }
   myglass.fill();
   cout<<"Filling Glass..."<<endl;
   cout<<"Is Full :";
   if(myglass.isFull())
   {
      cout<<"True"<<endl;
    
   }
   else
   {
      cout<<"False"<<endl;
   }
    
   return 0;
}
