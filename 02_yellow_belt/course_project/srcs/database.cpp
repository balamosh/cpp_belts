#include "database.h"

#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

tuple<int, int, int>	DateTuple(const Date& date) {
	return make_tuple(date.GetYear(), date.GetMonth(), date.GetDay());
}

void	Database::Add(const Date& date, const string& event) {	
	if (count(begin(date_to_events[date]), end(date_to_events[date]), event) == 0)
		date_to_events[date].push_back(event);
}

void	Database::Print(ostream& os) const {
	for (const auto& [date, events] : date_to_events) {
		for (const auto& event : events) {
			os << date << ' ' << event << endl;
		}
	}
}

string			Database::Last(const Date& date) const {
	if (date_to_events.empty())
		throw invalid_argument("No entries");
	auto	last = date_to_events.upper_bound(date);
	if (last == begin(date_to_events)) {
		throw invalid_argument("No entries");
	}
	last--;
		if (last->second.empty()) {
		throw invalid_argument("No entries");
	}
	auto	last_date = last->first;
	//auto	last_event = last->second.end();
	//last_event--;
	return (last_date.convert_to_string() + " " + last->second.back());
}