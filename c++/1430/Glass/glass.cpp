#include <iostream>
using namespace std;
#include "glass.h"

Glass::Glass()
{
   this->isfull = false;
   this->material = "glass";
   this->content = "";

}
Glass::Glass(string material)
{
   this->isfull = false;
   this->material = material;
}
Glass::Glass(string material,string content)
{
   this->material = material;
   this->content = content;
}
bool Glass::isFull()
{
  if(isfull)
  {
     return true;
  }
  else
  {
     return false;
    
  }
}
void Glass::fill()
{
   this->isfull=true;
   this->content = content;
}
void Glass::empty()
{
   this->isfull=false;
   this -> content = "water";
}
string Glass::getContent()
{
   return content;
}
string Glass::getMaterial()
{
   return material;
}