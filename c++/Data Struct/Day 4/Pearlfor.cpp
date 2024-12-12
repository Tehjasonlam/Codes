#include <iostream>
using namespace std;
struct pearl{
    int color;
    int size;
    pearl * hole;
};

int main() {
    pearl *p;
    p=new pearl;
    pearl *head=p; //saving the beg
    cout <<head<<"head\n";
    for(int i=0;i<10;i++)
    {  
       p->color = rand()%7;
       p->size = rand()%10+5;
       p->hole = nullptr;
       p = p->hole;
       p = new pearl;
       cout << p <<"inside the loop\n";
    }
    /*
    p=head;
    for(int i=0;i<10;i++)
    {  
        cout << "color" << p->color << endl;;
        cout << "size" << p->size << endl;;
        cout << p <<endl;
        p = p->hole;
    }*/
}
