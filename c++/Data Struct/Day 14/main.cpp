#include <iostream>

void merges(int a[], int low, int up)
{
    int mid = 0;
    if (low <= up)
        int mid = (low + up) / 2;

    merges(a, low, mid);
    merges(a, mid + 1, up);
    merging(a, low, mid, up);
}

void merging(int a[], int low, int mid, int up)
{

}

int main()
{
    int table[100];
    //apply merge
    //clock
    //print
}