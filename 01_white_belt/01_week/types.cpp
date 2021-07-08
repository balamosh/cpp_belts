#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Person
{
	string	name;
	string	surname;
	int	age;
};

int	main()
{
	int	x = -5;
	double	pi = 3.1415;
	bool 	logic_val = false;
	char	c = 'Z';
	string	hw = "Hello, world!\n";
	vector<int> nums = {1, 3, 5, 7};
	map<string, int> name_to_val;
	string	name;

	//use of strings and vectors
	
	/*
	cout << hw << "len = " << nums.size() << "\n";
	*/
	
	//use of dicts (map)
	
	/*
	name_to_val["one"] = 1;
	name_to_val["two"] = 2;
	cout << "Print string:\n";
	cin >> name;
	cout << name << " is " << name_to_val[name] << "\n";
	*/

	//use of custom type vector
	
	vector<Person> staff;
	staff.push_back({"Ivan", "Ivanov", 25});
	staff.push_back({"Petr", "Petrov", 32});

	cout << staff[0].name << "\n";
	return (0);
}
