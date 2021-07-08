#include <iostream>
#include <string>
#include <vector>
using namespace std;

int	main()
{
	// I
	int	x = 4;
	int	y = 5;
	if (x == y)
		cout << "equal";

	// II
	vector<int> nums = {1, 2, 3};
	for (auto el : nums)
		cout << el << ' ';
	cout << "\n";

	// III
	int	n = 5;
	int	sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += i;
	cout << sum << "\n";

	// IV	
	n = 5;
	sum = 0;
	int	i = 1;
	while (i <= n)
	{
		sum += i;
		i++;
	}
	cout << sum << "\n";
	return (0);
}
