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
	date_to_events[date].insert(event);
}

void	Database::Print(ostream& os) const {
	for (const auto& [date, events] : date_to_events) {
		for (const auto& event : events) {
			os << date << ' ' << event << endl;
		}
	}
}

string			Database::Last(const Date& date) const {
	auto	last = upper_bound(begin(date_to_events), end(date_to_events), date,
						[] (const Date& d, const pair<Date, set<string>>& x) {
							return (DateTuple(x.first) < DateTuple(d));
						});
	if (last == begin(date_to_events)) {
		throw invalid_argument("No entries");
	} else {
		last--;
		if ((*last).second.empty())
			throw invalid_argument("No entries");
		auto	last_date = (*last).first;
		auto	last_event = (*last).second.end();
		last_event--;
		return (last_date.convert_to_string() + " " + *last_event);
	}
	return ("");
}