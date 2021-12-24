#include <cstdint>
#include <algorithm>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
  SimpleVector() = default;
  explicit SimpleVector(size_t size);
  ~SimpleVector();

  T& operator[](size_t index);

  T* begin();
  T* end();

  size_t Size() const;
  size_t Capacity() const;
  void PushBack(T value);

  // При необходимости перегрузите
  // существующие публичные методы

private:
  // Добавьте сюда поля
	T		*data = nullptr;
	size_t	size_ = 0;
	size_t	capacity_ = 0;
};

template <typename T>
		SimpleVector<T>::SimpleVector(size_t size)
: data(new T[size])
, size_(size)
, capacity_(size)
{}

template <typename T>
		SimpleVector<T>::~SimpleVector() {
	delete[] data;
}

template <typename T>
T&		SimpleVector<T>::operator[](size_t index) {
	return (data[index]);
}

template <typename T>
T*		SimpleVector<T>::begin() {
	return (data);
}

template <typename T>	
T*		SimpleVector<T>::end() {
	return (data + size_);
}

template <typename T>
size_t	SimpleVector<T>::Size() const {
	return (size_);
}

template <typename T>
size_t	SimpleVector<T>::Capacity() const {
	return (capacity_);
}

template <typename T>
void	SimpleVector<T>::PushBack(T value) {
	if (data == nullptr) {
		data = new T[1];
		++capacity_;
	} else if (size_ == capacity_) {
		capacity_ *= 2;
		T	*new_data = new T[capacity_];
		move(begin(), end(), new_data);
		delete[] data;
		data = new_data;
	}
	data[size_++] = move(value);
}
