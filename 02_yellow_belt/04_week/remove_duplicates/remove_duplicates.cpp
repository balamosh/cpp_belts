#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void	RemoveDuplicates(vector<T>& elements)
{
	sort(begin(elements), end(elements));
	auto	last = unique(begin(elements), end(elements));
	elements.erase(last, end(elements));
}
