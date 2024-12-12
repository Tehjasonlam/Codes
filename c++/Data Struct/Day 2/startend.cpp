#include <iostream>
using namespace std;

struct st{
    int ps;
    float gpa;
};

class c2436{
    private:
        st *p;
        int size;
    public:
        c2436(){
            size = 120;
            p = new st[size];
            }
        ~c2436()
        {
            delete []p;
        }

};

int main() {

 
}