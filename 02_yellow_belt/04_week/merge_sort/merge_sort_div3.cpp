#include <vector>
#include <algorithm>

using namespace std;
	
template <typename RandomIt>
void	MergeSort(RandomIt range_begin, RandomIt range_end)
{
	auto	size = distance(range_begin, range_end);
	if (size < 2)
		return ;
	RandomIt	range_middle1 = next(range_begin, size / 3);
	RandomIt	range_middle2 = next(range_begin, 2 * size / 3);
	vector<typename RandomIt::value_type>	left(range_begin, range_middle1);
	vector<typename RandomIt::value_type>	middle(range_middle1, range_middle2);
	vector<typename RandomIt::value_type>	right(range_middle2, range_end);
	MergeSort(begin(left), end(left));
	MergeSort(begin(middle), end(middle));
	MergeSort(begin(right), end(right));
	vector<typename RandomIt::value_type>	tmp;
	merge(begin(left), end(left), begin(middle), end(middle), back_inserter(tmp));
	merge(begin(tmp), end(tmp), begin(right), end(right), range_begin);
}
