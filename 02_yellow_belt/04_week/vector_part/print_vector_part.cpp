#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	PrintVectorPart(const vector<int>& numbers)
{
	auto	it = find_if(begin(numbers), end(numbers),
			[](int x) {
				return (x < 0);
			});
	bool	first = true;	
	while (it != begin(numbers))
	{
		if (!first)
			cout << ' ';
		else
			first = false;
		--it;
		cout << *it;
	}
}
