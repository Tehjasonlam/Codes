#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void function2(int arr[],int size)
{
    if (size == 0)
        cout << arr[0];
        return;
    cout << arr[size];
    function2(arr,size-1);
}

int function3(int arr[], int size)
{
    int total = 0;

    for(int i = 0; i < size; i++)
        total += arr[i];

    return total;    
}

int function4(int arr[], int size)
{
    if (size == 0){
        return arr[0];
    }
    return arr[size-1] + function4(arr,size - 1);
}

int function4a(int arr[], int total, int size)
{
    if (size == 0){
        cout << total;
    }
    total += arr[size-1];
    function4a(arr, total, size);
}

int main(){
    
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    for (int i = 0;i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "End of this array" << endl;
    function2(arr,size-1);
    function4a();
    return 0;

}


