#include <string>
using namespace std;

class ReversibleString
{
	public:
		// constructors
		ReversibleString()
		{
			str = "";
			len = 0;
		}

		ReversibleString(const string& in_str)
		{
			str = in_str;
			len = str.size();
		}
		
		// methods
		string	ToString(void) const
		{
			return (str);
		}

		void	Reverse(void)
		{
			int	i = 0;
			int	j = len - 1;
			while (i < j)
			{
				char	tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
				i++;
				j--;
			}
		}

	private:
		string	str;
		int	len;
};
