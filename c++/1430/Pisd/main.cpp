#include <iostream>
using namespace std;

int main()
{
    cout << "hello world \n";

    string firstname , lastname;
    cout << "first name ";
    cin >> firstname;
    cout << "last name ";
    cin >> lastname;
    
    cout << "full name is: " << firstname << " " << lastname;
    return 0;
}