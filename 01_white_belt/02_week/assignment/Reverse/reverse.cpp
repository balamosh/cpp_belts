#include <vector>
using namespace std;

void	Reverse(vector<int>& v)
{
	int	i = 0;
	int	size = v.size();

	while (i < size - 1 - i)
	{
		int	tmp = v[i];
		v[i] = v[size - 1 - i];
		v[size - 1 - i] = tmp;
		i++;
	}
}
