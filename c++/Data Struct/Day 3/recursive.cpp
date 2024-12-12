#include <iostream>

using namespace std;

void ex(int a)
{
    if(a==10)
        cout << "bye ";
    else{
        cout << " a before \t" << a << endl;
        a++;
        ex(a);
        cout << "\n\n";
        cout << a << " paper \n\n\n";
    }
}
void print(int a, int b){
    if (a == b)
        cout << "end number " << b << endl;
    else{
        cout << a << endl;
        a++;
        print(a,b);
    }
}
int m(int a, int b){
    if (b==1)
        return a;
    else
        return a+m(a,b-1);
}

int main(){
    ex(7);
    cout << m(5,3) << endl;
    print(1,10);
}