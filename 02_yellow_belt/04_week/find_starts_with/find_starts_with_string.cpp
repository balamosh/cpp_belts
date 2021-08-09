#include <utility>
#include <algorithm>
#include <string>

#include <iostream>

using namespace std;
	
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix)
{
	auto	lower = lower_bound(range_begin, range_end, prefix,
					[] (string elem, string val) {
						return (elem.substr(0, val.size()) < val);
					});
	auto	upper = upper_bound(range_begin, range_end, prefix,
					[] (string val, string elem) {
						return (val < elem.substr(0, val.size()));
					});
	return {lower, upper};
}
