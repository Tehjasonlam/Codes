#include <iostream>

using namespace std;

int main()
{
    int num;
    int even = 0;
    int odd = 0;
    
    while(num > 0)
    {
        int rem = num % 10;
        if (rem % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        num = num / 10;
        
    }
    
    
    if (even > odd)
    {
        cout << "EVEN";
    }
    else if (even < odd)
    {
        cout << "ODD";
    }
    else
    {
        cout << "EQUAL";
    }
    
    return 0;
}