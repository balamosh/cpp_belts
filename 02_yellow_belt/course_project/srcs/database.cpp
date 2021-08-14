#include "database.h"

#include <tuple>
#include <pair>

using namespace std;

tuple	DateTuple(const Date& date) {
	return {date.GetYear(), date.GetMonth(), date.GetDay()}
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

template <Class Func>
int				Database::RemoveIf(Func predicate) {
	int	ret = 0;
	for (const auto& [date, events] : date_to_events) {
		for (const auto& event : events) {
			if (predicate(date, event)) {
				date_to_events[date].erase(event);
				ret++;
			}
		}
	}
	return (ret);
}

template <Class Func>
vector<string>	Database::FindIf(Func predicate) {
	vector<string>	ret;
	for (const auto& [date, events] : date_to_events) {
		for (const auto& event : events) {
			if (predicate(date, event)) {
				ret.push_back(event);
			}
		}
	}
	return (ret);
}



string			Database::Last(const Date& date) {
	const auto	last = upper_bound(begin(date_to_events), end(date_to_events),
						[] (const pair& lhs, const pair& rhs) {
							return (DateTuple(lhs.first) < DateTuple(rhs.first));
						});
	if (last == begin(date_to_events) || !date_to_events.at((*last).first.empty())) {
		throw invalid_argument("No entries");
	} else {
		last--;
		auto	last_date = (*last).first;
		auto	last_event = (*last).first.end();
		last_event--;
		return (last_date.to_string() + " " + *last_event);
	}
}