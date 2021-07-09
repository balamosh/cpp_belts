#include <iostream>
#include <string>

using namespace std;

bool	IsPalindrom(string str);

int	main()
{
	string	str;

	cin >> str;
	/*
	if (IsPalindrom(str))
		cout << "true";
	else
		cout << "false";
	cout << endl;
	*/
	cout << IsPalindrom(str) << endl;
	return (0);
}
