#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
class PriorityCollection {
public:
  using Id = size_t; /* тип, используемый для идентификаторов */
  // Добавить объект с нулевым приоритетом
  // с помощью перемещения и вернуть его идентификатор
  Id Add(T object);

  // Добавить все элементы диапазона [range_begin, range_end)
  // с помощью перемещения, записав выданные им идентификаторы
  // в диапазон [ids_begin, ...)
  template <typename ObjInputIt, typename IdOutputIt>
  void Add(ObjInputIt range_begin, ObjInputIt range_end,
           IdOutputIt ids_begin);
  
  // Добавить по Id
  void	Add(Id id, T object);

  // Определить, принадлежит ли идентификатор какому-либо
  // хранящемуся в контейнере объекту
  bool IsValid(Id id) const;

  // Получить объект по идентификатору
  const T& Get(Id id) const;

  // Увеличить приоритет объекта на 1
  void Promote(Id id);

  // Получить объект с максимальным приоритетом и его приоритет
  pair<const T&, int> GetMax() const;

  // Аналогично GetMax, но удаляет элемент из контейнера
  pair<T, int> PopMax();

  // Размер контейнера
  size_t	Size() const;

private:
  // Приватные поля и методы

	Id	GetNewId() const;

	set<pair<int, Id>>		ids;
	map<Id, pair<T, int>>	id_to_object;
};

template <typename T>
typename PriorityCollection<T>::Id
PriorityCollection<T>::GetNewId() const {
	if (id_to_object.size() == 0) {
		return (Id(0));
	} else {
		return (id_to_object.rbegin()->first + 1);
	}
}

template <typename T>
void
PriorityCollection<T>::Add(Id id, T object) {
	ids.insert({0, id});
	id_to_object[id] = {move(object), 0};
}

template <typename T>
typename PriorityCollection<T>::Id
PriorityCollection<T>::Add(T object) {
	Id	id = GetNewId();
	Add(id, object);
	return (id);
}

template <typename T>
template <typename ObjInputIt, typename IdOutputIt>
void
PriorityCollection<T>::Add(ObjInputIt range_begin, ObjInputIt range_end,
							IdOutputIt ids_begin) {
	while (range_begin != range_end) {
		*(ids_begin++) = Add(move(*(range_begin++)));
	}
}

template <typename T>
bool
PriorityCollection<T>::IsValid(Id id) const {
	return (id_to_object.count(id) > 0);
}

template <typename T>
const T&
PriorityCollection<T>::Get(Id id) const {
	return (id_to_object.at(id).first);
}

template <typename T>
void
PriorityCollection<T>::Promote(Id id) {
	int	priority = id_to_object[id].second++;
	ids.erase({priority, id});
	ids.insert({priority + 1, id});
}

template <typename T>
pair<const T&, int>
PriorityCollection<T>::GetMax() const {
	return (id_to_object.at(ids.rbegin()->second));
}

template <typename T>
pair<T, int>
PriorityCollection<T>::PopMax() {
	Id				id = ids.rbegin()->second;
	pair<T, int>	node = move(id_to_object[id]);
	ids.erase({node.second, id});
	id_to_object.erase(id);
	return (node);
}

template <typename T>
size_t
PriorityCollection<T>::Size() const {
	return (ids.size());
}
