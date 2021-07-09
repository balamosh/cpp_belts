#include <iostream>

using namespace std;

int	main()
{
	int	a, b, mod;

	cin >> a >> b;
	mod = a % b;
	while (mod != 0)
	{
		a = b;
		b = mod;
		mod = a % b;
	}
	cout << b << endl;
}
