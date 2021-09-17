#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Deque
{
public:
	Deque() : size(0) {}

	bool		Empty() const { return (size == 0); }

	size_t		Size() const { return (size); }
	
	T&			operator[](size_t index) {
		if (index < vecFront.size()) {
			auto	i = vecFront.size() - index - 1;
			return (vecFront[i]);
		}
		else {
			auto	i = index - vecFront.size();
			return (vecBack[i]);
		}
	}
	const T&	operator[](size_t index) const {
		if (index < vecFront.size()) {
			auto	i = vecFront.size() - index - 1;
			return (vecFront[i]);
		}
		else {
			auto	i = index - vecFront.size();
			return (vecBack[i]);
		}
	}

	T&			At(size_t index) {
		if (index < size)
			return ((*this)[index]);
		else
			throw out_of_range(to_string(index) + " >= " + to_string(size));	
	}
	const T&	At(size_t index) const {
		if (index < size)
			return ((*this)[index]);
		else
			throw out_of_range(to_string(index) + " >= " + to_string(size));
	}

	T&			Back() { return (vecBack.size() > 0 ? vecBack.back() : vecFront.front()); }
	const T&	Back() const { return (vecBack.size() > 0 ? vecBack.back() : vecFront.front()); }

	T&			Front() { return (vecFront.size() > 0 ? vecFront.back() : vecBack.front()); }
	const T&	Front() const { return (vecFront.size() > 0 ? vecFront.back() : vecBack.front()); }

	void		PushBack(const T& elem) {
		vecBack.push_back(elem);
		size++;
	}
	void		PushFront(const T& elem) {
		vecFront.push_back(elem);
		size++;
	}

private:
	vector<T>	vecBack;
	vector<T>	vecFront;
	size_t		size;
};
