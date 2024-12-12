#include <iostream>
using namespace std;

struct st
{
    int ps;
    float gpa;
    st *next;
};

int main()
{
    st *p = nullptr;
    p = new st;

    /*p-> ps = 123;
    p-> gpa = 4.0;
    p-> next = new st;
    
    p = p->next;

    p->ps = 456;
    p->gpa = 3.7;
    p->next = new st;

    p = p->next;
    
    p->ps = 789;
    p->gpa = 2.0;
    p->next = nullptr;*/

    for(int i=0; i < 100; i++)
    {
        p->ps = i * 100 * 734 / 3;
        p->gpa = i * 7.6 / 2.3;
        p->next = new st;

        p = p->next;
    }



}