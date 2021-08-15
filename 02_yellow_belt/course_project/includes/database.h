#pragma once

#include "date.h"

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Database {
public:
	void			Add(const Date& date, const string& event);
	void			Print(ostream& os) const;
	
	template <typename Func>
	int				RemoveIf(Func predicate) {
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
	
	template <typename Func>
	vector<string>	FindIf(Func predicate) const {
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

	string			Last(const Date& date) const;

private:
	map<Date, set<string>>	date_to_events;
};
