#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector();
	explicit SimpleVector(size_t size);
	~SimpleVector();

	T&		operator[](size_t index);

	T*		begin();
	T*		end();

	size_t	Size() const;
	size_t	Capacity() const;
	void	PushBack(const T& value);

private:
  // Добавьте поля для хранения данных вектора
	T		*data;
	size_t	size_;
	size_t	capacity_;
};

template <typename T>
		SimpleVector<T>::SimpleVector()
: data(nullptr)
, size_(0)
, capacity_(0)
{}

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
void	SimpleVector<T>::PushBack(const T& value) {
	if (data == nullptr) {
		data = new T[1];
		++capacity_;
	} else if (size_ == capacity_) {
		capacity_ *= 2;
		T	*new_data = new T[capacity_];
		for (size_t i = 0; i < size_; ++i) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
	}
	data[size_++] = value;
}
