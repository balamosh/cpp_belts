#pragma once

#include "date.h"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class Database {
public:
	void			Add(const Date& date, const string& event);
	void			Print(ostream& os) const;
	
	template <typename Func>
	int				RemoveIf(Func predicate) {
		int	ret = 0;
		vector<Date>	clean;
		for (auto& [_date, events] : date_to_events) {
			Date	date = _date;
			auto	size = events.size();
			auto	it = stable_partition(begin(events), end(events),
											[predicate, date] (const string& elem) {
												return (!predicate(date, elem));
											});
			if (it == begin(events)) {
				ret += size;
				clean.push_back(date);
			} else {
				ret += distance(it, end(events));
				events.erase(it, end(events));
			}
		}
		for (const auto& date : clean) {
			date_to_events.erase(date);
		}
		return (ret);
	}
	
	template <typename Func>
	vector<string>	FindIf(Func predicate) const {
		vector<string>	ret;
		for (const auto& [date, events] : date_to_events) {
			for (const auto& event : events) {
				if (predicate(date, event)) {
					ostringstream	out;
					out << date << " " << event;
					ret.push_back(out.str());
				}
			}
		}
		return (ret);
	}

	string			Last(const Date& date) const;

private:
	map<Date, vector<string>>	date_to_events;
	map<Date, set<string>>		date_to_events_set;
};
