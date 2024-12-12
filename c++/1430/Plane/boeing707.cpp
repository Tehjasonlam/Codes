#include "boeing707.hpp"
#include <iostream>
using namespace std;

Boeing707::Boeing707(float fuel, float cargo): Plane(fuel, cargo)
{
}

std::string Boeing707:: get_type() const
{
   return "Boeing707";
}
float Boeing707:: get_takeoff_distance() const
{
   return 0.8+(get_cargo()/60)*0.5;
}

float Boeing707:: get_travel_distance() const
{
   return  (get_fuel()/ 26000) * 10000 * (1 - (get_cargo() / 60)*0.3);
}
