#include <iostream>

using namespace std;

struct pearl
{
    int color;
    int size;
    pearl * hole;

};

class necklace{
    private:
        pearl *head;
    public:
        necklace(){head = nullptr;}
        void insertpearl(int c, int s);
        void print();

};