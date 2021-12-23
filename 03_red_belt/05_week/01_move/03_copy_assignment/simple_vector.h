#pragma once

#include <cstdlib>
#include <algorithm>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector();
	explicit SimpleVector(size_t size);
	SimpleVector(const SimpleVector<T>& other);
	~SimpleVector();

	T&		operator[](size_t index);
	void	operator=(const SimpleVector<T>& other);

	T*		begin();
	T*		end();
	const T*	begin() const;
	const T*	end() const;

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
		SimpleVector<T>::SimpleVector(const SimpleVector<T>& other)
: data(new T[other.capacity_])
, size_(other.size_)
, capacity_(other.capacity_)
{
	std::copy(other.begin(), other.end(), begin());
}

template <typename T>
		SimpleVector<T>::~SimpleVector() {
	delete[] data;
}

template <typename T>
T&		SimpleVector<T>::operator[](size_t index) {
	return (data[index]);
}

template <typename T>
void	SimpleVector<T>::operator=(const SimpleVector<T>& other) {
	if (other.size_ <= capacity_) {
		std::copy(other.begin(), other.end(), begin());
		size_ = other.size_;
	} else {
		SimpleVector<T>	tmp(other);
		std::swap(tmp.data, data);
		std::swap(tmp.size_, size_);
		std::swap(tmp.capacity_, capacity_);
	}
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
const T*	SimpleVector<T>::begin() const {
	return (data);
}

template <typename T>	
const T*	SimpleVector<T>::end() const {
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
