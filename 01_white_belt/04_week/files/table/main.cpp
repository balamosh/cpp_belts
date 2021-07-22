#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int	main(void)
{
	string		path = "input.txt";
	ifstream	file(path);
	if (file)
	{
		int	n, m;
		file >> n >> m;
		int	nbr;
		//cout << setfill('.');
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				file >> nbr;
				cout << setw(10) << nbr;
				if (j < m - 1)
				{
					char	c;
					file >> c;
					cout << ' ';
				}
			}
			if (i < n - 1)
				cout << endl;
		}
	}
	else
	{
		cout << "Cannot open \"" << path << "\"" << endl;
	}
	return (0);
}
