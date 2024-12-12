#include <iostream>

using namespace std;

int main()
{
    int hour1,min1,sec1,hour2,min2,sec2;
    
    // Define additional variables if needed
    
    // Reading the first time
    cin >> hour1 >> min1 >> sec1;
    
    // Reading the second time
    cin >> hour2 >> min2 >> sec2;
    
    int time1 = hour1*3600 + min1*60 + sec1;
    int time2 = hour2*3600 + min2*60 + sec2;

    // Determine the max time
    if ((time1) >= (time2))
    {
        cout << "Max time: " << endl;
        cout << "Hour: " << hour1 << endl;
        cout << "Minute: " << min1 << endl;
        cout << "Second: " << sec1 << endl;
    }
    else
    {
        cout << "Max time: " << endl;
        cout << "Hour: " << hour2 << endl;
        cout << "Minute: " << min2 << endl;
        cout << "Second: " << sec2 << endl;
    }
    return 0;
}