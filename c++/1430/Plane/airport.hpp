#ifndef AIRPORT_H
#define AIRPORT_H
#include "boeing707.hpp"
#include "dc8.hpp"
#include <iostream>
using namespace std;

class Airport
{
   private:
   float runway;
   Plane *planes[10];
   int num_planes;
   
   public:
   Airport(float runway);
   ~Airport();
   bool add_plane(Plane* p);
   Plane* get_plane(int index);
   bool confirm_take_off(int index, float trip_distance);
};


#endif
