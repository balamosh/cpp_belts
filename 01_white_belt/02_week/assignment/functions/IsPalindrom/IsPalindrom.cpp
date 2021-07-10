#include <string>

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
