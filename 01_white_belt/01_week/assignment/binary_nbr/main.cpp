#include <iostream>

using namespace std;

static void	ft_putnbr_binary(int n)
{
	if (n >= 2)
		ft_putnbr_binary(n / 2);
	cout << n % 2;
}

int	main()
{
	int	n;

	cin >> n;
	ft_putnbr_binary(n);
	cout << endl;
	return (0);
}
