#include <iostream>
using namespace std;

int main()
{
    int m,n;
    int sumInt = 0;
    int i;

    cin >> m >> n;

    for (i = m; i <= n; i++)
    {
        if(i % 2 ==0)
        {
            sumInt = sumInt + i;
        }
       
    }
 

    cout << "The sum of the even values between " << m << " and " << n << " is: " << sumInt << endl;
    return 0;
}