#include <iostream>

using namespace std;

struct pearl
{
    int color;
    int size;
    pearl * hole;

};

int main(){
    pearl *p;
    p = new pearl;
    p->color = 5;
    p->size = 10;
    p->hole = nullptr;
   
    //link it
    p->hole = new pearl;
    /*
    p->hole->color = 2;
    p->hole->size = 7;
    p->hole->hole = nullptr; 
    */
    p = p->hole;
    p->color = 2;
    p->size = 7;
    p->hole = nullptr;

    //third pear
    p->hole = new pearl;
    p = p->hole;
    p->color = 3;
    p->size = 11;
    p->hole = nullptr;
}