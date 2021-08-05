#include <set>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
vector<T>	FindGreaterElements(const set<T>& elements, const T& border)
{
	vector<T>	answer;
	auto	it = find_if(begin(elements), end(elements),
			[border](T elem) {
				return (elem > border);
			});
	while (it != end(elements))
	{
		answer.push_back(*it);
		it++;
	}
	return (answer);
}
