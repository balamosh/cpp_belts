#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;
	vector<string>	arr(n);
	for (int i = 0; i < n; i++)
	{
		string	elem;
		cin >> elem;
		arr[i] = elem;
	}
	sort(arr.begin(), arr.end(), [](string a, string b){ 
		for (auto& c : a)
			c = tolower(c);
		for (auto& c : b)
			c = tolower(c);
		return (a < b); 
		});
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	return (0);
}
