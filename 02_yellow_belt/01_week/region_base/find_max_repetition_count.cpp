#include <iostream>
#include <tuple>
#include <vector>
#include <map>
//#include "structures.cpp"

using namespace std;

/*tuple<const string&,
	const string&,
	const map<Lang, string>&,
	const int64_t&>*/
auto	tieRegion(const Region& region)
{
	return tie(region.std_name,
			region.parent_std_name,
			region.names,
			region.population);
}

bool	operator < (const Region& lhs, const Region& rhs)
{
	return tieRegion(lhs) < tieRegion(rhs);
}

int	FindMaxRepetitionCount(const vector<Region>& regions)
{
	map<Region, int>	unique_count;
	int			max = 0;
	for (const auto& r : regions)
	{
		if (++unique_count[r] > max)
			max = unique_count[r];
	}
	return (max);
}
