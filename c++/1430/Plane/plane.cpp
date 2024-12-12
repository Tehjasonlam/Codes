#include "plane.hpp"


Plane::Plane(float fuel, float cargo)
{
   this -> fuel = fuel;
   this ->cargo = cargo;
}

void Plane:: set_cargo(float cargo)
{
   this-> cargo = cargo;
}

float Plane:: get_cargo() const
{
   return cargo;
}

void Plane:: set_fuel(float fuel)
{
   this-> fuel = fuel;
}

float Plane :: get_fuel() const
{
   return fuel;
}

std::string Plane::get_type() const
{
    return "Generic Plane";
}

