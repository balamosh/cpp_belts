#include <iostream>
#include <string>
#include <vector>
using namespace std;

int	main()
{
	// I
	int	x = 4;
	string	y = "hello";
	cout << x << ' ' << y << "\n";

	// II (how NOT to do)
	/*
	vector<int> d = {1, 3};
	cout << d;
	*/

	// III
	int	x3, y3;
	cin >> x3 >> y3;
	cout << x3 + y3 << "\n";

	// IV
	string	name;
	cin >> name;
	cout << "Hello, " << name << "\n";
	
	// V
	string	surname;
	cin >> name >> surname;
	cout << "Hello, " << name << ' ' << surname << "\n";

	return (0);
}
