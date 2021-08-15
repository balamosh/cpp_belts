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
		for (auto& [date, events] : date_to_events) {
			for (auto it = begin(events); it != end(events); ) {
				if (predicate(date, *it)) {
					it = events.erase(it);
					ret++;
				} else {
					++it;
				}
			}
		}
		for (auto it = begin(date_to_events); it != end(date_to_events); ) {
			if (it->second.empty()) {
				it = date_to_events.erase(it);
			} else {
				++it;
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
};
