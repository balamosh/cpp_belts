#pragma once

#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

class EventList {
public:
    void Add(const string& event);

    const vector<string>& GetAll() const;

    template <typename Func>
    int RemoveIf(Func predicate) {
        auto split_point = stable_partition(event_vector.begin(), event_vector.end(), predicate);
        int result = split_point - event_vector.begin();
        for (auto i = event_vector.begin(); i != split_point; ++i) {
            event_set.erase(*i);
        }
        event_vector.erase(event_vector.begin(), split_point);

        return result;
    }

private:
    set<string> event_set;
    vector<string> event_vector;
};
