#include <iostream>
#include "listcars.h"

using namespace std;

void listcars::print()
{
    car *cu = head;
    while( cu !=nullptr)
    {
        cout << cu->year;
        cout << cu->price;
        //update
        cu = cu->next;
    }
}

void listcars::addatbeg(int y, float p)
{
    car *temp = new car;
    temp->year = y;
    temp->price =  p;

    temp->next = head;
}
