#include <iostream>
#include "pile.h"
using namespace std;
void pile::push(int np)
{
    // 1-create
    book *tmp = new book;

    // 2-fill
    tmp->price = np;
    tmp->next = nullptr;
    // link it
    tmp->next = top;
    top = tmp;
}
void pile::print()
{
    book *cu = top;
    while (cu != nullptr)
    {
        cout << cu->price;
        cu = cu->next;
    }
}
void pile::pop(int &v)
{
    book *tmp = top;
    v = top->price;
    top = tmp->next;
    delete tmp;
}