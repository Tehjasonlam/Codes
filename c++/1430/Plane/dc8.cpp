#include "dc8.hpp"
#include <iostream>
using namespace std;

DC8::DC8(float fuel,float cargo,int dsi) : Plane(fuel, cargo)
{
   this -> dsi = dsi;
}

int DC8:: get_dsi()
{
   return dsi;
}

std::string DC8:: get_type() const
{
   return "DC8";
}

float DC8:: get_takeoff_distance() const
{
   return 0.9+(get_cargo()/50)*0.4;
}

float DC8:: get_travel_distance() const
{

   float distance = (get_fuel()/ 24000) * 9600 * (1 - (get_cargo() / 50)*0.2);
   if(get_cargo() > 40)
   {
      distance = distance/2;
      return distance;
   }
   return distance;
}