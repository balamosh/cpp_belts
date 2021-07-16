#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main(void)
{
	int	n;
	cin >> n;
	vector<int>	arr(n);
	for (int i = 0; i < n; i++)
	{
		int	elem;
		cin >> elem;
		//arr.push_back(elem);
		arr[i] = elem;
	}
	sort(arr.begin(), arr.end(), [](int a, int b){ return (abs(a) < abs(b)); });
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
	return (0);
}
