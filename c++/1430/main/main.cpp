#include <iostream>
using namespace std;

/*
void func(int array[], int size)
{
   for(int i=0; i<size; i++)
      array[i] += 3;
}

int main() 
{
   int arr[] = {1,2,3,4,5,6,7};
   func(arr,7);
   for (int i=0; i<7; i++)
      cout << arr[i] << " ";
   return 0;
}
*/
/*
int main()
{
    char sentence[] = "I love COSC 1430!!";
    char *ptr = sentence;
    int size = sizeof(sentence);
    for (int i = 0; i < size; i+=2) {
       cout << *(ptr + i);
    }
}
*/
/*
#include <iostream>

using namespace std;

int main()
{
    int option;
    do
    {
        cin >> option;
        switch (option)
        {
            case 1: cout << "Option 1" << endl;
                    break;
            case 2: cout << "Option 2" << endl;
                    break;
            case 3: cout << "Option 3" << endl;
                    break;
            case 4: cout << "Option 4" << endl;
                    break;
            case 0: break;
            default:cout << "Invalid Option" << endl;
                    break;
        }
    }
    while(option > 0);

    return 0;
}
*/
/*
int main()
{
    int arr[6];
    
    for(int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    

    for(int i = 0; i < 6; i++)
    {
        if(arr[i]%2 == 0)
        {
            cout << arr[i];
        }
    }
    return 0;
}
*/

/*
#include <cmath>
int main()
{
    int x = 1;
    int y = 3;
    double result = x / y;
    if (result == 0.333333)
        cout << "Method1";
    else if (fabs(result - 0.333333) < 0.0001)
        cout << "Method2";
    else
        cout << "Error";
}
*/
/*
#include <iomanip>

int main()
{
    int size;
    cin >> size;
    int *array = new int(size);// initialize the dynamic array
    
    for (int i = 0; i < size ; i++)
        cin >> array[i];
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0)
            result++;
    }
    cout << "Number of negative values: " << result << endl;
    delete [] array;
    return 0;
}
*/
/*
#include <iostream>

using namespace std;

bool digitInNumber(int number, int digit)
{
    if(number/10 == number%digit)
    {
        return true;
    }
    else
    {
        return false;

    }
}

int main()
{
    int minVal, maxVal, digit;
    cin >> minVal >> maxVal >> digit;
    for (int number = minVal; number <= maxVal; number++)
    {
        if (digitInNumber(number,digit)==true)
            cout << number << " "; 
    }
}
*/
/*
int locEven(int arr[],int size)
{
    for(int i = 0 ; i < size; i++)
    {
        if(arr[i]%2 == 0)
        {
            if (arr[i] >= arr[0])
            {
                arr[0]= arr[i];
            }
        }
        else if(arr[i]%2 == 1)
        {
            arr[0] = 0;
        }
        
    }
    return arr[0];
}

int main()
{
    int arr[6];
    int size = 6;
    for(int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    cout << locEven(arr,size) << endl;
    return 0;
}
*/

#include <iostream>

using namespace std;

int main()
{

    const int MAXSIZE = 10;
    int nElements;
    int array[MAXSIZE];
    
    cin >> nElements;
    
    if (nElements > MAXSIZE)
    {
        cout << "Incorrect number of elements" << endl;
    }
    else
    {
        for (int i=0;i<nElements;i++)
            cin >> array[i];
        // Traverse the array in reverse order (from right to left) using a loop
        {
            // Use a conditional to check if the value from the array is odd
            if (array % 2 != 1)
            {

                cout << array[i] << " ";
            }
        }
    }
    
    return 0;
}