#ifndef GLASS_H
#define GLASS_H
using namespace std;
#include <string>

class Glass
{
public:
Glass();
Glass(string material);
Glass(string material,string content);
   
   bool isFull() ;
   void fill();
   void empty();
   string getContent();
   string getMaterial();

private:
   string content;
   string material;
   bool isfull;
};

#endif