#include <iostream>
#include <string>
using namespace std;

int main() {
	int par;
	int strokes;
    int i;
	string name;
    cin >> par; 
    cin >> strokes;

    if (par == 3 || par == 4 || par ==5)
    {
        i = (strokes - par);
        if (i == -2)
        {
            name = "Eagle";
        }
        else if (i == -1)
        {
            name = "Birdie";
        }
        else if (i == 0)
        {
            name = "Par";
        }
        else
        {
            name = "Bogey";
        }
        
        
        cout << name << endl;
    }
    else
    {
        cout << "Error" << endl;
    }


	return 0;
}