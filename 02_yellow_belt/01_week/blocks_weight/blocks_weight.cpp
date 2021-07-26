#include <iostream>

using namespace std;

class Block
{
	public:
		Block()
		{
			x = 0;
			y = 0;
			z = 0;
		}

		Block(int new_x, int new_y, int new_z)
		{
			x = new_x;
			y = new_y;
			z = new_z;
		}

		uint64_t	GetVolume() const
		{
			uint64_t	result = 1;
			result *= x;
			result *= y;
			result *= z;
			return (result);
		}

	private:
		int	x;
		int	y;
		int	z;
};

istream&	operator>>(istream& stream, Block& block)
{
	int	x, y, z;
	stream >> x >> y >> z;
	block = Block(x, y, z);
	return (stream);
}

bool		operator<(const Block& lhs, const Block& rhs)
{
	return (lhs.GetVolume() < rhs.GetVolume());
}

int	main()
{
	int		size, density;
	cin >> size >> density;
	uint64_t	sum = 0;
	for (int i = 0; i < size; i++)
	{
		Block	block;
		cin >> block;
		sum += block.GetVolume();
	}
	cout << sum * density << endl;
	return (0);
}
