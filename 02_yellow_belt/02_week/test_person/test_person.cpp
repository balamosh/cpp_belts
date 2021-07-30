#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
//#include "names1.cpp"

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

/*
class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};
*/

void	TestUnknown()
{
	{
		Person	p;
		AssertEqual(p.GetFullName(2000), "Incognito", "");
	}
	{
		Person	p;
		p.ChangeLastName(2010, "last_name");
		AssertEqual(p.GetFullName(2009), "Incognito", "");
		AssertEqual(p.GetFullName(2010), "last_name with unknown first name", "");
		p.ChangeFirstName(2000, "first_name");
		AssertEqual(p.GetFullName(1000), "Incognito", "");
		AssertEqual(p.GetFullName(2000), "first_name with unknown last name", "");
		AssertEqual(p.GetFullName(2010), "first_name last_name", "");
		AssertEqual(p.GetFullName(2050), "first_name last_name", "");
	}
	{
		Person	p;
		p.ChangeLastName(2010, "last_name1");
		p.ChangeLastName(2020, "last_name2");
		p.ChangeFirstName(2025, "first_name1");
		p.ChangeFirstName(2035, "first_name2");
		AssertEqual(p.GetFullName(1000), "Incognito", "");
		AssertEqual(p.GetFullName(2010), "last_name1 with unknown first name", "");
		AssertEqual(p.GetFullName(2020), "last_name2 with unknown first name", "");
		AssertEqual(p.GetFullName(2040), "first_name2 last_name2", "");
	}
}

int main() {
  TestRunner runner;
  runner.RunTest(TestUnknown, "TestUnknown");
  // добавьте сюда свои тесты
  return 0;
}
