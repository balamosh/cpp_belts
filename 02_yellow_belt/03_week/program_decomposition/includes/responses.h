#pragma once

#include <iostream>

using namespace std;

struct BusesForStopResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  // Наполните полями эту структуру
	string	message = "";
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
