#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "enter string ";
    cin >> str;
    char c;
    cout << "enter char ";
    cin >> c;
    
    if (str.find(c) == string::npos) 
    {
        cout << "Character not found" << endl;
        
    } 
    else 
    {
        cout << "Character found" << endl;
    }
    

    
    return 0;
} 