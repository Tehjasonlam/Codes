#include "airport.hpp"
#include <iostream>
using namespace std;

Airport::Airport(float runway)
{
   this -> runway = runway;
   this -> num_planes = 0; 
}

Airport::~Airport() 
{
   for(int index=0;index<num_planes;index++)
   {
      delete planes[index];
   }
}

bool Airport:: add_plane(Plane* p) 
{
   if(num_planes < 10)
   {
      planes[num_planes] = p;
      num_planes++;
      return true;
   }
   else
   {
      return false;
   }
}

Plane* Airport:: get_plane(int index)
{

   if(index >=0 && index < num_planes)
   {
      return planes[index];
   }
   else
   {
      return nullptr;
   }
}

bool Airport:: confirm_take_off(int index, float trip_distance) 
{
   if(index >=0 && index < num_planes)
   {
      if(planes[index]->get_takeoff_distance() > runway)
      {
        std::cout << planes[index]->get_type() << ": cannot take off because the runway is too short!" << std::endl;
        return false;
      }
      else if(planes[index]->get_type() == "DC8" && ((DC8*)planes[index])->get_dsi() >= 30)
      {
         std::cout << "DC8: cannot take off because it needs inspection!" << std::endl;
         return false;
      }
      else if(planes[index]->get_travel_distance() < trip_distance)
      {
         std::cout << planes[index]->get_type() << ": cannot take off because of insufficient fuel!" << std::endl;
         return false;
      }
      else
      {
         return true;
      }
    }
    else
    {
       return false;
    }
}