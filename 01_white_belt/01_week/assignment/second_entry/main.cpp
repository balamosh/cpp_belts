#include <iostream>
#include <string>

using namespace std;

int	main()
{
	string	str;
	int	f = -2;
	int	i = 0;

	cin >> str;
	for (auto c : str)
	{
		if (c == 'f')
		{
			if (f == -2)
				f = - 1;
			else
			{
				f = i;
				break ;
			}
		}
		i++;
	}
	cout << f << endl;
	return (0);
}
