#include <iostream>

class htable
{
private:
    int *elt;
    int size;
    int hfunction(int); // pass int get index
    int h2(int);

public:
    htable(int s = 10)
    {
        size = s;
        elt = new int[s];
    }

    void insert_direct(int x)
    {
        int i = hfunction(x);
        elt[i] = x;
    }
    insert_linearp
        insert_quad
            insert_doubleh
};

int main()
{
    htable mine(7);
    htable yours;
}