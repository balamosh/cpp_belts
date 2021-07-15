#include <iostream>
#include <set>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;
	set<string>	unique;
	for (int i = 0; i < n; i++)
	{
		string	s;
		cin >> s;
		unique.insert(s);
	}
	cout << unique.size() << endl;
	return (0);
}
