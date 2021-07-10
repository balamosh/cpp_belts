#include <vector>
using namespace std;

vector<int>	Reversed(const vector<int>& v)
{
	vector<int>	v_new;

	for (int i = v.size() - 1; i >= 0; i--)
		v_new.push_back(v[i]);
	return (v_new);
}
