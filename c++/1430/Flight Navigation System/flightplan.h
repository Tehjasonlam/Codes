#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include "structs.h"
#include <iostream>
using namespace std;


class FlightPlan
{
   private:
   Plane current_plane;
   Waypoint* waypoints;
   int num_waypoints;
   
   public:
   FlightPlan(Plane);
   ~FlightPlan();
   FlightPlan(FlightPlan& copy);
   FlightPlan& operator = (const FlightPlan& copy);
   Plane get_current_plane();
   Waypoint get_waypoint(int);
   void set_waypoint(int,Waypoint);
   void save_waypoints(string string);
   void load_waypoints(string string);
   bool check_flightplan();
   
};
#endif