#include <iostream>
using namespace std;

void	UpdateIfGreater(const int first, int& second);

int	main()
{
	int	a, b;

	cin >> a >> b;
	cout << "a == " << a << endl;
	cout << "b == " << b << endl;
	cout << "Update:\n";
	UpdateIfGreater(a, b);
	cout << "a == " << a << endl;
	cout << "b == " << b << endl;
	return (0);
}
