#include <vector>
#include <algorithm>

using namespace std;
	
template <typename RandomIt>
void	MergeSort(RandomIt range_begin, RandomIt range_end)
{
	auto	size = distance(range_begin, range_end);
	if (size < 2)
		return ;
	RandomIt	range_middle = next(range_begin, size / 2);
	vector<typename RandomIt::value_type>	left(range_begin, range_middle);
	vector<typename RandomIt::value_type>	right(range_middle, range_end);
	MergeSort(begin(left), end(left));
	MergeSort(begin(right), end(right));
	merge(begin(left), end(left), begin(right), end(right), range_begin);
}
