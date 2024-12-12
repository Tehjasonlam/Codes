#include "flightplan.h"

int main()
{
    cout << "Please enter the plane's fuel, speed, fuel usage, and max altitude:" <<endl;
    float fuel, speed, fuel_usage, max_altitude;
    cin >> fuel>> speed>> fuel_usage>> max_altitude;
    
    Plane p = {fuel, speed, fuel_usage, max_altitude};
    FlightPlan fp(p);
    
    cout << "Please enter the flightplan's file name:" <<endl;
    string fname;
    cin >> fname;
    fp.load_waypoints(fname);
    if (fp.check_flightplan()){
        cout << "The flight plan is valid!";
    }else{
        cout << "The flight plan is not valid, please double-check your waypoints!";
    }
    
    return 0;
}