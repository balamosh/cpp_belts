#include <iostream>
using namespace std;

int	main()
{
	// I
	int	x = 4;
	int	y = 5;
	cout << (x + y) * (x - y) << "\n";

	// II
	if (x == y)
		cout << "equal\n";
	else
		cout << "not equal\n";
	// III
	string	sx = "abc";
	string	sy = "def";
	if (sx < sy)
		cout << "less\n";
	else
		cout << "not less\n";

	return (0);
}
