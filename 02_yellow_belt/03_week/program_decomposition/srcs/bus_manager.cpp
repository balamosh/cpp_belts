#include "bus_manager.h"
#include <sstream>

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
	// Реализуйте этот метод
	buses_to_stops[bus] = stops;
	for (const string& stop : stops) {
		stops_to_buses[stop].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
	// Реализуйте этот метод
	stringstream		msg;
	if (stops_to_buses.count(stop) == 0) {
		msg << "No stop";
	} 
	else {
		bool	first = true;
		for (const string& bus : stops_to_buses.at(stop)) {
			if (!first)
				msg << ' ';
			else
				first = false;
			msg << bus;
		}
	}
	BusesForStopResponse	out;
	out.message = msg.str();
	return (out);
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
	// Реализуйте этот метод
	stringstream		msg;
	if (buses_to_stops.count(bus) == 0) {
		msg << "No bus";
	} 
	else {
		bool	first = true;
		for (const string& stop : buses_to_stops.at(bus)) {
	  		if (!first)
				msg << endl;
			else
				first = false;
			msg << "Stop " << stop << ": ";
	  		if (stops_to_buses.at(stop).size() == 1) {
	    			msg << "no interchange";
	  		} 
			else {
				bool	first = true;
	    			for (const string& other_bus : stops_to_buses.at(stop)) {
	      				if (bus != other_bus) {
						if (!first)
							msg << ' ';
						else
							first = false;
						msg << other_bus;
	      				}
	    			}
	  		}
		}
	}
	StopsForBusResponse	out;
	out.message = msg.str();
	return (out);
}

AllBusesResponse BusManager::GetAllBuses() const {
	// Реализуйте этот метод
	stringstream	msg;
	if (buses_to_stops.empty()) {
		msg << "No buses";
	} 
	else 
	{
		bool	first = true;
		for (const auto& bus_item : buses_to_stops) {
			if (!first)
				msg << endl;
			else
				first = false;
			msg << "Bus " << bus_item.first << ": ";
			bool	first_sp = true;
			for (const string& stop : bus_item.second) {
				if (!first_sp)
					msg << ' ';
				else
					first_sp = false;
				msg << stop;
			}
		}
	}
	AllBusesResponse	out;
	out.message = msg.str();
	return (out);
}
