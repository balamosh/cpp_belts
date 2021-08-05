#include "person.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Это пример функции, его не нужно отправлять вместе с функцией PrintStats
template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void	PrintStats(vector<Person> persons)
{
	cout << "Median age = "
		<< ComputeMedianAge(begin(persons), end(persons)) << endl;

	auto	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::FEMALE);
			});
	cout << "Median age for females = "
		<< ComputeMedianAge(begin(persons), last) << endl;
	
	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::MALE);
			});
	cout << "Median age for males = "
		<< ComputeMedianAge(begin(persons), last) << endl;
	
	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::FEMALE &&
					p.is_employed);
			});
	cout << "Median age for employed females = "
		<< ComputeMedianAge(begin(persons), last) << endl;
	
	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::FEMALE &&
					!p.is_employed);
			});
	cout << "Median age for unemployed females = "
		<< ComputeMedianAge(begin(persons), last) << endl;
	
	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::MALE &&
					p.is_employed);
			});
	cout << "Median age for employed males = "
		<< ComputeMedianAge(begin(persons), last) << endl;
	
	last = partition(begin(persons), end(persons),
			[] (Person p) {
				return (p.gender == Gender::MALE &&
					!p.is_employed);
			});
	cout << "Median age for unemployed males = "
		<< ComputeMedianAge(begin(persons), last) << endl;
}
