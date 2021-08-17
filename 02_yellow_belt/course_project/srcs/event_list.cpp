#include "event_list.h"

void EventList::Add(const string& event) {
    auto insert_result = event_set.insert(event);
    if (insert_result.second) {
        event_vector.push_back(event);
    }
}

const vector<string>& EventList::GetAll() const {
    return event_vector;
}
