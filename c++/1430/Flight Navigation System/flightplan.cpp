#include <fstream> 
using namespace std;
#include "flightplan.h"

FlightPlan::FlightPlan(Plane plane) 
{
	this -> current_plane = plane;
	this -> num_waypoints = 0;
	this -> waypoints = nullptr;
}
FlightPlan::~FlightPlan()
{
	if (waypoints != nullptr) 
	{
	   waypoints = nullptr;
	}
}

FlightPlan::FlightPlan(FlightPlan& copy)
{
	this -> current_plane.fuel = copy.current_plane.fuel;	
	this -> current_plane.speed = copy.current_plane.speed;
	this -> current_plane.fuel_usage = copy.current_plane.fuel_usage;
	this -> current_plane.max_altitude = copy.current_plane.max_altitude;
	this -> num_waypoints = copy.num_waypoints;
	this -> waypoints = new Waypoint[num_waypoints];

	for (int index = 0; index < num_waypoints; index++) 
	{
		waypoints[index].altitude = copy.waypoints[index].altitude;
		waypoints[index].distance = copy.waypoints[index].distance;
		waypoints[index].heading = copy.waypoints[index].heading;
	}
}

FlightPlan& FlightPlan::operator=(const FlightPlan& copy)
{
	this -> current_plane.fuel = copy.current_plane.fuel;	
	this -> current_plane.speed = copy.current_plane.speed;
	this -> current_plane.fuel_usage = copy.current_plane.fuel_usage;
	this -> current_plane.max_altitude = copy.current_plane.max_altitude;
	this -> num_waypoints = copy.num_waypoints;
	this -> waypoints = new Waypoint[num_waypoints];

	for (int index = 0; index < num_waypoints; index++) 
	{
		waypoints[index].altitude = copy.waypoints[index].altitude;
		waypoints[index].distance = copy.waypoints[index].distance;
		waypoints[index].heading = copy.waypoints[index].heading;
	}
	return *this;
}
Plane FlightPlan::get_current_plane()
{
	return current_plane;
}
Waypoint FlightPlan::get_waypoint(int index) 
{
	if (num_waypoints > index) 
	{
		return waypoints[index];
	}
	else 
	{	
		return Waypoint();
	}
}
void FlightPlan::set_waypoint(int index, Waypoint newpoint) 
{
	if (num_waypoints > index) {
		waypoints[index] = newpoint;
	}
}

void FlightPlan::save_waypoints(string filename)
{
	ofstream outputFile;
	outputFile.open(filename);
	outputFile << num_waypoints << endl;

	for (int index = 0; index < num_waypoints; index++) {
		outputFile << waypoints[index].heading << " " << waypoints[index].distance << " " << waypoints[index].altitude << endl;
	}

	outputFile.close();
}

void FlightPlan::load_waypoints(string filename) 
{
   ifstream inputfile;
	inputfile.open(filename);

	if (inputfile) 
	{
	   int numPoints = 0;
		inputfile >> numPoints;

		num_waypoints = numPoints;
		waypoints = new Waypoint[num_waypoints];
		int index = 0;
		while (!inputfile.eof()) {
			inputfile >> waypoints[index].heading >> waypoints[index].distance >> waypoints[index].altitude;
			index++;
		}
	}
	else if (!inputfile) 
	{
		cout << filename << " could not be opened. " << endl;
	}
}

bool FlightPlan::check_flightplan()  
{
	float current_fuellevel;
	current_fuellevel = current_plane.fuel;
	for (int index = 0; index < num_waypoints; index++) {
	   
		if (waypoints[index].altitude > current_plane.max_altitude) 
		{
			return false;
		}

		float hours;
		hours = waypoints[index].distance / current_plane.speed;
		float fuelrequired ;
		fuelrequired = current_plane.fuel_usage * hours;
		current_fuellevel -= fuelrequired;
		
		if (current_fuellevel < 0) 
		{
			return false;
		}
	}

	return true;
}