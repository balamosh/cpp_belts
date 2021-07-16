#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class SortedStrings
{
	public:
		void		AddString(const string& s)
		{
			strs.push_back(s);
		}
		vector<string>	GetSortedStrings()
		{
			Sort();
			return (strs);
		}
	private:
		vector<string>	strs;
		void		Sort()
		{
			sort(strs.begin(), strs.end());
		}
};
