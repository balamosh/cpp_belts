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
	//if (range_begin == range_end)
	//	return {range_end, range_end};
	string	s_prefix;
	s_prefix.push_back(prefix);
	auto	lower = lower_bound(range_begin, range_end, s_prefix);
	auto	upper = upper_bound(range_begin, range_end, s_prefix);
	cout << *lower << ' ' << *upper << endl;
	return {lower, upper};
}
