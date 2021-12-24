#include "test_runner.h"
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  // Напишите реализацию функции,
  // не копируя сортируемые элементы
	auto	size = distance(range_begin, range_end);
	if (size < 2)
		return ;
	RandomIt	range_middle1 = next(range_begin, size / 3);
	RandomIt	range_middle2 = next(range_begin, 2 * size / 3);
	vector<typename RandomIt::value_type>	left(make_move_iterator(range_begin), make_move_iterator(range_middle1));
	vector<typename RandomIt::value_type>	middle(make_move_iterator(range_middle1), make_move_iterator(range_middle2));
	vector<typename RandomIt::value_type>	right(make_move_iterator(range_middle2), make_move_iterator(range_end));
	MergeSort(begin(left), end(left));
	MergeSort(begin(middle), end(middle));
	MergeSort(begin(right), end(right));
	vector<typename RandomIt::value_type>	tmp;
	merge(make_move_iterator(begin(left)), make_move_iterator(end(left)), 
			make_move_iterator(begin(middle)), make_move_iterator(end(middle)), 
			back_inserter(tmp));
	merge(make_move_iterator(begin(tmp)), make_move_iterator(end(tmp)), 
			make_move_iterator(begin(right)), make_move_iterator(end(right)), 
			range_begin);
}

void TestIntVector() {
  vector<int> numbers = {6, 1, 3, 9, 1, 9, 8, 12, 1};
  MergeSort(begin(numbers), end(numbers));
  ASSERT(is_sorted(begin(numbers), end(numbers)));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  return 0;
}
