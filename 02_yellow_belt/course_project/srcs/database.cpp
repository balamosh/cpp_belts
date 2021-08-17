#include "database.h"

using namespace std;

void Database::Add(const Date &date, const string &event) {
    storage[date].Add(event);
}

void Database::Print(ostream &os) const {
    for (const auto& [date, events]: storage) {
        for (const auto& event : events.GetAll()) {
            os << date << " " << event << endl;
        }
    }
}

Entry Database::Last(const Date &date) const {
    auto it = storage.upper_bound(date);

    if (it == storage.begin()) {
        throw invalid_argument("");
    }
    --it;
    return {it->first, it->second.GetAll().back()};
}


ostream &operator<<(ostream &stream, const Entry &e) {
    return stream << e.date << ' ' << e.event;
}

bool operator==(const Entry &lhs, const Entry &rhs) {
    return tie(lhs.date, lhs.event) == tie(rhs.date, rhs.event);
}

bool operator!=(const Entry &lhs, const Entry &rhs) {
    return tie(lhs.date, lhs.event) != tie(rhs.date, rhs.event);
}
