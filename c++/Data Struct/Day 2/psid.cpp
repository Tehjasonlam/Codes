#include <iostream>
using namespace std;

struct st{
    int ps;
    float gpa;
    st *next;
};

int main() {
    st Ellie;
    Ellie.ps = 123;
    Ellie.gpa = 3;
    Ellie.next = nullptr;
    //dynamic
    st* p;
    p = new st;
    p->ps = 122;
    p->gpa = 2.3;
    p->next= nullptr; //nobody next to this person

    //intialize a pointer
    p->next = new st;
    p=p->next;
    p->ps = 77;
    p->gpa = 4.0;
    p->next = nullptr;
    
    //another one
    p->next = new st;

 
}