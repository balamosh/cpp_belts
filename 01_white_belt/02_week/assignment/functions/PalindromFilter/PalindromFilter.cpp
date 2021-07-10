#include <string>
#include <vector>

using namespace std;

bool	IsPalindrom(string str)
{
	int	i, j, len;

	len = str.size();
	i = 0;
	j = len - 1;
	while (i < len)
	{
		if (str[i] != str[j])
			return (false);
		i++;
		j--;
	}
	return (true);
}

vector<string>	PalindromFilter(vector<string> strs, int min_len)
{
	vector<string>	out;

	for (auto s : strs)
	{
		if (s.size() >= min_len && IsPalindrom(s))
			out.push_back(s);
	}
	return (out);
}
