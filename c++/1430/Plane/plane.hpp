#ifndef PLANE_H
#define PLANE_H
#include <string>
using namespace std;

class Plane
{
   private:
   float fuel;
   float cargo;
   
   public:
   Plane(float fuel, float cargo);
   virtual ~Plane() {}
   void set_cargo(float cargo);
   void set_fuel(float fuel);
   float get_cargo() const;
   float get_fuel() const;
   virtual std::string get_type() const;
   
   virtual float get_takeoff_distance() const = 0 ;
   virtual float get_travel_distance() const = 0;
};

#endif