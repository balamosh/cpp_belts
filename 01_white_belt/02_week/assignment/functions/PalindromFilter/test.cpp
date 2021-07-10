#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>	PalindromFilter(vector<string> strs, int min_len);

int	main()
{
	vector<string>	strs = {"abc", "bcd", "", "a", "ab", "aba", "aaaa", "abba"};

	cout << "Orig vec:" << endl;
	for (auto s : strs)
		cout << s << endl;
	int	min_len = 4;
	vector<string>	out;
	cout << "Filtering palindromes with min len = " << min_len << endl;
	out = PalindromFilter(strs, min_len);
	for (auto s : out)
		cout << s << endl;
	return (0);
}
