#ifndef DC8_H
#define DC8_H
#include <iostream>
using namespace std;
#include "plane.hpp"

class DC8 : public Plane
{
   private:
   int dsi;
   
   
   public:
   DC8(float fuel,float cargo,int dsi);
   ~DC8() {}
   int get_dsi();
   std::string get_type() const;
   float get_takeoff_distance() const;
   float get_travel_distance() const;
};


#endif