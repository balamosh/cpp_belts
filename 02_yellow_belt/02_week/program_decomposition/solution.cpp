#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  // Реализуйте эту функцию
	string operation_code;
    	cin >> operation_code;
	if (operation_code == "NEW_BUS") {
		q.type = QueryType::NewBus;
	      cin >> q.bus;
	      int stop_count;
	      cin >> stop_count;
	      q.stops.resize(stop_count);
	      for (string& stop : q.stops) {
		cin >> stop;
      		}
    	} 
	else if (operation_code == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
	      cin >> q.stop;
    	} 
	else if (operation_code == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;	      
		cin >> q.bus;
    	}
	else if (operation_code == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
    	}
	return is;
}

struct BusesForStopResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}

struct AllBusesResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
    // Реализуйте этот метод
	buses_to_stops[bus] = stops;
	for (const string& stop : stops) {
		stops_to_buses[stop].push_back(bus);
      	}

  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
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

  StopsForBusResponse GetStopsForBus(const string& bus) const {
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

  AllBusesResponse GetAllBuses() const {
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
private:
	map<string, vector<string>>	buses_to_stops, stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
