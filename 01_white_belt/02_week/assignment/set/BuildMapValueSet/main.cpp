#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m);

int	main(void)
{
	set<string>	str_set;
	str_set = BuildMapValuesSet({
			{1, "odd"},
			{2, "even"},
			{3, "odd"},
			{4, "even"}
			});
	for (auto s : str_set)
	{
		cout << s << endl;
	}
	return (0);
}
