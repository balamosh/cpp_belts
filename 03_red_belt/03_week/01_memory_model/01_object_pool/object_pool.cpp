#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <typename T>
class ObjectPool {
public:
	T*		Allocate() {
		T	*elem = TryAllocate();
		if (elem == nullptr) {
			elem = new T;
			allocated.insert(elem);
		}
		return (elem);
	}

	T*		TryAllocate() {
		T	*elem;
		if (deallocated.size() > 0) {
			elem = deallocated.front();
			deallocated.pop();
			allocated.insert(elem);
			return (elem);
		}
		return (nullptr);
	}

	void	Deallocate(T* object) {
		if (allocated.count(object) == 0) {
			throw invalid_argument("invalid pointer");
		}
		else {
			allocated.erase(object);
			deallocated.push(object);
		}
	}

	~ObjectPool() {
		for (T *obj : allocated) {
			delete obj;
		}
		while(deallocated.size() > 0) {
			delete deallocated.front();
			deallocated.pop();
		}
	}
private:
	set<T *>	allocated;
	queue<T *>	deallocated;
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
