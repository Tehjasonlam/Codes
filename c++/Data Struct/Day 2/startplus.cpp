#include <iostream>
using namespace std;

struct st{
    int ps;
    float gpa;

};

int main(){
    
    //int *p
    st *p = new st[5]; //dynamic allocation
    for(int i = 0; i < 5; i++)
    {
        (*p).ps = 123;
        p->ps = 123;  //->
        p->gpa = rand()%4 + 1;

    }

    delete [] p; //delete allocation

    st Elle; //static allocation
    Elle.ps = 456; //....
    Elle.gpa = 4.0;

}