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
	template <Class Func>
	int				RemoveIf(Func predicate);
	template <Class Func>
	vector<string>	FindIf(Func predicate) const;
	string			Last(const Date& date) const;
private:
	map<date, set<string>>	date_to_events;
};
