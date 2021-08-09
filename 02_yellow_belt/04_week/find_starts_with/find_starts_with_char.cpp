#include <utility>
#include <algorithm>
#include <string>

#include <iostream>

using namespace std;
	
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix)
{
	auto	lower = lower_bound(range_begin, range_end, prefix,
					[prefix] (string elem, char val) {
						return (elem[0] < val);
					});
	auto	upper = upper_bound(range_begin, range_end, prefix,
					[prefix] (char val, string elem) {
						return (val < elem[0]);
					});
	return {lower, upper};
}
