#include <iostream>
using namespace std;
void bub(int a[], int n)
{
    int tmp, swap, comp;
    for (int pass = 1; pass < n; pass +)
        for (int i = 0; i < n - pass; i++)
        {
            comp++;
            if (a[i] > a[i + 1])
            {
                swap++;
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
            cout << "nb of comp" << comp;
            cout << "nb of swaps" << swap;
        }
}
int main()
{
    int a[1000];
    for
        a[i] = rand() % 100;
  clock_t beg = clock();
  bub(a, 1000);
  clock_t end = clock();
  cout << "time taken" << (end - beg) ;
}