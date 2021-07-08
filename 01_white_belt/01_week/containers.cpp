#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int	main()
{
	// I
	string	s = "abcdefg";
	for (char c : s)
	{
		cout << c << ", ";
	}
	cout << "\n";

	// II
	vector<int> nums = {1, 5, 2, 3, 5};
	for (int c : nums)
	{
		cout << c << ", ";
	}
	cout << "\n";
	// III
	vector<string> my_vec = {"1", "5", "2", "3", "5"};
	for (auto c : my_vec)
	{
		cout << c << ", ";
	}
	cout << "\n";
	
	// III
	int quantity = 0;
	for (int c : nums)
	{
		if (c == 5)
			quantity++;
	}
	cout << "There are " << quantity << " fives" << "\n";

	// IV
	quantity = count(begin(nums), end(nums), 5);
	cout << "There are " << quantity << " fives" << "\n";

	// V
	sort(begin(nums), end(nums));
	for (auto x : nums)
	{
		cout << x << " ";
	}
	cout << "\n";

	// VI
	my_vec = {"hello", "world!", "milk"};
	sort(begin(my_vec), end(my_vec));
	for (auto x : my_vec)
	{
		cout << x << " ";
	}
	cout << "\n";

	return (0);
}
