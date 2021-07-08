#include <iostream>
#include <cmath>

using namespace std;

int	main()
{
	double	a, b, c;

	cin >> a >> b >> c;
	if (a != 0)
	{
		double	D = b * b - 4 * a * c;
		if (D == 0)
		{
			double	x = -b / (2 * a);
			cout << x;
		}
		else if (D > 0)
		{
			double	x1, x2;
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			cout << x1 << " " << x2;
		}
	}
	else if (b != 0)
	{
		double	x = -c / b;
		cout << x;
	}
	return (0);
}
