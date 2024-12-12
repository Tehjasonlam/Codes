#include <iostream>
#include <string>
using namespace std;

int countCharInArray(char ch, char message[], int size)
{
    int count = 0;
   
    for (int i = 0; i < size; i++)
    {
        if (message[i] ==  ch)
        {
            ++ count;
        }
    }
    return count;
    
}

int main()
{
    char sen[15];
    char letter;
    int si; 

    cout << "Enter the Sentence: " ;
    cin >> sen;
    cout << "\nEnter the Letter you want: ";
    cin >> letter;
    
    si = sizeof(sen);
    
    cout << countCharInArray(letter , sen, si) << endl;

    return 0;
}