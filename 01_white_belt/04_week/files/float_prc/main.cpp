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
		double	nbr;
		while (true)
		{
			file >> nbr;
			if (file.ignore(1))
			{
				cout << fixed << setprecision(3);
				cout << nbr << endl;
			}
			else
				break ;
		}
	}
	else
	{
		cout << "Cannot open \"" << path << "\"" << endl;
	}
	return (0);
}
