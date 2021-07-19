#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class FunctionPart
{
	public:
		FunctionPart(char new_operation, double new_value)
		{
			operation = new_operation;
			value = new_value;
		}

		double	Apply(double x) const
		{
			if (operation == '+')
				return (x + value);
			if (operation == '-')
				return (x - value);
			else
				return (x);
		}

		void	Invert(void)
		{
			if (operation == '+')
				operation = '-';
			else if (operation == '-')
				operation = '+';
		}
	
	private:
		char	operation;
		double	value;
};

class Function
{
	public:
		void 	AddPart(char new_operation, double new_value)
		{
			parts.push_back({new_operation, new_value});
		}

		double	Apply(double x) const
		{
			for (auto part : parts)
			{
				x = part.Apply(x);
			}
			return (x);
		}

		void	Invert(void)
		{
			for (auto& part : parts)
			{
				part.Invert();
			}
			reverse(begin(parts), end(parts));
		}
	
	private:
		vector<FunctionPart>	parts;
		/*
		void	PrintFunc(void) const
		{
			cout << "--- FUNC ---" << endl;
			for (auto part : parts)
				cout << part.operation << " " << part.value << endl;
			cout << "------------" << endl;
		}*/
};
