#include <iostream>
#include <fstream>
using namespace std;

int	main(void)
{
	string		path = "input.txt";
	ifstream	file(path);
	if (file)
	{
		string	line;
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		cout << "Cannot open \"" << path << "\"" << endl;
	}
	return (0);
}
