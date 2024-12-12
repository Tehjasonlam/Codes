#ifndef BOEING707_H
#define BOEING707_H
#include "plane.hpp"
#include <iostream>
using namespace std;

class Boeing707 : public Plane
{
public:
   Boeing707(float fuel, float cargo);
   ~Boeing707() {}
   std::string get_type() const;
   float get_takeoff_distance() const;
   float get_travel_distance() const;

};

#endif
