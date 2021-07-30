#include "responses.h"

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  // Реализуйте эту функцию
	os << r.message;
  return os;
}
