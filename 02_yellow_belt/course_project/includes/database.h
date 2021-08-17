#pragma once

#include "date.h"
#include "event_list.h"

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

struct Entry {
	Date	date;
	string	event;
};

ostream &operator<<(ostream &os, const Entry &e);

bool operator==(const Entry &lhs, const Entry &rhs);

bool operator!=(const Entry &lhs, const Entry &rhs);

class Database {
public:
    void Add(const Date &date, const string &event);

    void Print(ostream &os) const;

    template<typename Func>
    vector<Entry> FindIf(Func predicate) const {
        vector<Entry> result;
        for (auto& [date, events] : storage) {
            for (const auto& event : events.GetAll()) {
                if (predicate(date, event)) {
                    result.push_back(Entry{date, event});
                }
            }
        }
        return result;
    }

    template <typename Func>
    int RemoveIf(Func predicate) {
        int result = 0;
        for (auto& [date, events] : storage) {
            const Date& cpy_date = date;
            result += events.RemoveIf([=](const string& event) {
                return predicate(cpy_date, event);
            });
        }
        for (auto it = storage.begin(); it != storage.end(); ) {
            if (it->second.GetAll().empty()) {
                storage.erase(it++);
            } else {
                ++it;
            }
        }
        return result;
    }

    Entry Last(const Date &date) const;

private:
    map<Date, EventList> storage;
};

ostream &operator<<(ostream &stream, const pair<Date, string> &p);