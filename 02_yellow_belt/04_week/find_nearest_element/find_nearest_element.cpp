#include <set>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border)
{
	const auto	right = numbers.lower_bound(border);
	if (right == begin(numbers))
		return (right);
	const auto	left = prev(right);
	if (right == end(numbers))
		return (left);
	return (*right - border < border - *left ? right : left);
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
