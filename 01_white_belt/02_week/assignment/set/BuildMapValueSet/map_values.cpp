#include <set>
#include <map>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string>	out;
	for (auto item : m)
	{
		out.insert(item.second);
	}
	return (out);
}
