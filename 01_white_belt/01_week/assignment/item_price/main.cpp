#include <iostream>

using namespace std;

int	main()
{
	double	n, a, b, x, y;

	cin >> n >> a >> b >> x >> y;
	if (n > b)
		n = n * (100 - y) / 100;
	else if (n > a)
		n = n * (100 - x) / 100;
	cout << n;
	return (0);
}
