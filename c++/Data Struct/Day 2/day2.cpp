#include <iostream>
using namespace std;

int main(){
    int a; //static
    a = 10; 
    int *p=0;
    p = &a;
    cout << a << endl;
    cout << p << endl;

    int *q = new int;
    *q = 10; //dynamic
    cout << *q/10 << endl;
    delete q;



}