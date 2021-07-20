#include <iostream>
#include <fstream>
using namespace std;

int	main(void)
{
	string		in_path = "input.txt";
	string		out_path = "output.txt";
	ifstream	in_file(in_path);
	ofstream	out_file(out_path, ios_base::app);
	if (in_file)
	{
		string	line;
		while (getline(in_file, line))
		{
			out_file << line << endl;
		}
	}
	else
	{
		cout << "Cannot open \"" << in_path << "\"" << endl;
	}
	return (0);
}
