#include <iostream>
using namespace std;

int main()
{
    int a[10];
    int maxInt;
    int i;
    for(i = 0;i < 10; i++)
    {
        cout << "Enter Int: ";
        cin >> a[i];
    }
    maxInt = a[0];
    for(i = 1;i < 10; i++) 
    {
        if(maxInt < a[i])
        {
            maxInt = a[i];
        }
    }
    cout << endl << maxInt;
    return 0;

}
