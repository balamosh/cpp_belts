#include <iostream>
#include <string>
#include <vector>

using namespace std;

int	main()
{
	vector<string>	strs;
	for (int i = 0; i < 3; i++)
	{
		string	str;
		cin >> str;
		strs.push_back(str);
	}
	string min_s = strs[0];
	for (auto s : strs)
	{
		if (s < min_s)
			min_s = s;
	}
	cout << min_s;
	return (0);
}
