#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
