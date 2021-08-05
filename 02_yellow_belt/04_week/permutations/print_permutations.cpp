#include <iostream>
#include <algorithm>

using namespace std;

void	PrintPermutation(string p)
{
	bool	first = true;
	for (char c : p)
	{
		if (!first)
			cout << ' ';
		else
			first = false;
		cout << c;
	}
	cout << endl;
}

void	PrintPermutations(int n)
{
	string	p;
	for (int i = 0; i < n; i++)
	{
		p.push_back(n - i + '0');
	}
	PrintPermutation(p);
	while (prev_permutation(begin(p), end(p)))
	{
		PrintPermutation(p);
	}
}

int	main()
{
	int	n;
	cin >> n;
	PrintPermutations(n);
	return (0);
}
