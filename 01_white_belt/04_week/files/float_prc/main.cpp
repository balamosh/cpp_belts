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
		cout << fixed << setprecision(3);
		double	nbr;
		while (file >> nbr)
		{
			cout << nbr << endl;
		}
	}
	else
	{
		cout << "Cannot open \"" << path << "\"" << endl;
	}
	return (0);
}
