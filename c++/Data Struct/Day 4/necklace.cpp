#include <iostream>
#include "necklace.h"
using namespace std;

void necklace::insertpearl(int c, int s)
{
    //1 - create a pearl
    pearl *tmp = new pearl;

    //2 - fill
    tmp->color = c;
    tmp->size = s;
    tmp->hole = nullptr;

    //3 - link it
    if (head == 0)
        head = tmp;
    else
    {
        tmp->hole = head;
        head = tmp;
    }

}

void necklace::print()
{
    pearl *cu = head;

    while (cu->hole !=nullptr)
    {
        cout << cu->color << cu->size;
        cu = cu->hole; // traversing
    }
    
}