#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    cout << "1. Add";
    cout << "2. Sub";
    cout << "3. Mul";
    cout << "4. Div";
    int option;
    cin >> option;
    
    if(option >= 1 && option <=4)
    {
        int result;
        int value1, value2;
        cout << "Enter the first value: ";
        cin >> value1;
        cout << "Enter the second value: ";
        cin >> value2;
        switch(option)
        {
            case 1: result = value1 + value2;
                    break;
            case 2: result = value1 - value2;
                    break;
            case 3: result = value1 * value2;
                    break;
            case 4: result = (double)value1 / value2;
                    break;
        }
        cout << "Result = " << fixed << setprecision(2) result << endl;

        if (option == 1)
        {
        result = value1 + value2;
        }
        else if (option == 2)
        {
        result = value1 - value2;
        }
        else if (option == 3)
        {
        result = value1 * value2;
        }
        else 
        {
        result = (double)value1 / value2;
        }
        cout << "Result = " << fixed << setprecision(2) result << endl;
        
    
    }
}
 
