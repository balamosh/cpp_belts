#include "test_runner.h"
#include "profile.h"
#include <vector>
#include <future>
#include <functional>
using namespace std;

// Реализуйте шаблон класса Paginator

template <typename Iterator>
class Page {
private:
	Iterator	first, last;
	size_t		size_;
public:
	Page(Iterator f, Iterator l)
	: first(f)
	, last(l)
	, size_(distance(f, l))
	{}

	Iterator	begin() const {
		return (first);
	}
	Iterator	end() const {
		return (last);
	}
	size_t		size() const {
		return (size_);
	}
};

template <typename Iterator>
class Paginator {
private:
	vector<Page<Iterator>>	pages;
public:
	Paginator(Iterator begin, Iterator end, size_t page_size) {
		for (size_t left = distance(begin, end); left > 0; ) {
			size_t current_page_size = min(page_size, left);
			Iterator current_page_end = next(begin, current_page_size);
			pages.push_back({begin, current_page_end});
			left -= current_page_size;
			begin = current_page_end;
    	}
	}

	auto	begin() const {
		return (pages.begin());
	}
	auto	end() const {
		return (pages.end());
	}
	size_t	size() const {
		return (pages.size());
	}
};

template <typename C>
auto	Paginate(C& c, size_t page_size) {
  // Реализуйте этот шаблон функции
  return (Paginator(c.begin(), c.end(), page_size));
}

template <typename ContainerOfVectors>
int64_t	CalculateMatrixPartSum(const ContainerOfVectors& matrix_part) {
	int64_t	sum = 0;
	for (const auto& row : matrix_part) {
		for (auto elem : row) {
			sum += elem;
		}
	}
	return (sum);
}

int64_t CalculateMatrixSum(const vector<vector<int>>& matrix) {
  // Реализуйте эту функцию
	int64_t	sum = 0;
	vector<future<int64_t>>	futures;
	for (auto page : Paginate(matrix, 2000)) {
		futures.push_back(
			async([=] {
				return (CalculateMatrixPartSum(page));
			})
		);
		//futures.push_back(async(CalculateMatrixPartSum, ref(page)));
	}
	for (auto& f : futures) {
		sum += f.get();
	}
	return (sum);
}

void TestCalculateMatrixSum() {
  const vector<vector<int>> matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };
  ASSERT_EQUAL(CalculateMatrixSum(matrix), 136);
}

void	TestBigMatrix() {
	vector<vector<int>> v(9000, vector<int>(9000, 1));
	{ LOG_DURATION("big matrix");
		ASSERT_EQUAL(CalculateMatrixSum(v), 9000 * 9000);
	}
}

int main() {
  TestRunner tr;
  //RUN_TEST(tr, TestCalculateMatrixSum);
  RUN_TEST(tr, TestBigMatrix);
}
