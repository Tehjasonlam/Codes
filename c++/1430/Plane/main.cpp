#include "airport.hpp"
#include "boeing707.hpp"
#include "dc8.hpp"


int main() {

	float runway;

	int num_planes;

	cin >> runway >> num_planes;

	Airport ap(runway);

	for (int i = 0; i < num_planes; i++) {
		string type;
		float fuel, cargo;
		
		cin >> type >> fuel >> cargo;
		
		if (type == "Boeing707") {
			Boeing707* p = new Boeing707(fuel, cargo);
			ap.add_plane(p);
		}
		else if (type == "DC8") {
			int dsi;
			cin >> dsi;
			DC8* p = new DC8(fuel, cargo, dsi);
			ap.add_plane(p);
		}
	}

	for (int i = 0; i < num_planes; i++) {
		float distance;
		cin >> distance;
		if (ap.confirm_take_off(i, distance)) {
			cout << ap.get_plane(i)->get_type() << ": ready to take off." << endl;
		}
	}

	return 0;
}