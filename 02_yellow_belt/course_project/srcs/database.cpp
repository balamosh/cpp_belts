#include "database.h"

using namespace std;

void	Database::Add(Date date, string event) {	
	date_to_events[date].insert(event);
}

void	Database::Print(ostream& os) const {
	for (const auto& [date, events] : date_to_events) {
		for (const auto& event : events) {
			os << date << ' ' << event << endl;
		}
	}
}
