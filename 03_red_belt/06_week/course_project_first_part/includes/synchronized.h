#pragma once

#include <mutex>
using namespace std;

// Реализуйте шаблон Synchronized<T>.
// Метод GetAccess должен возвращать структуру, в которой есть поле T& value.
template <typename T>
class Synchronized {
public:
  explicit Synchronized(T initial = T())
  : value(move(initial))
  {}

  struct Access {
	  lock_guard<mutex>	lock;
    T& ref_to_value;
  };

  Access GetAccess() {
	  return {lock_guard<mutex>(m), value};
  }
private:
  T value;
  mutex	m;
};
