#ifndef  STRUCTS_H
#define STRUCTS_H

struct Plane 
{
	float fuel, speed, fuel_usage, max_altitude;
};

struct Waypoint
{
	float heading, distance, altitude;
};

#endif