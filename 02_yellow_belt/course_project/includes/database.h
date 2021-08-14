#pragma once

#include "date.h"

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Database {
public:
	void	Add(Date date, string event);
	void	Print(ostream& os) const;
private:
	map<date, set<string>>	date_to_events;
};
