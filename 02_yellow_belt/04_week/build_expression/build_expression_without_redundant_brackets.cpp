#include <iostream>
#include <deque>

using namespace std;

int	main()
{
	int	x;
	cin >> x;
	
	int	n;
	cin >> n;

	deque<string>	answer;
	answer.push_back(to_string(x));
	bool	prev_op_low = false;
	for (int i = 0; i < n; i++)
	{
		string	op;
		int		new_x;
		cin >> op >> new_x;
		if (prev_op_low)
		{
			if (op == "*" || op == "/")
			{
				answer.push_front("(");
				answer.push_back(")");
				prev_op_low = false;
			}
		}
		else if (op == "+" || op == "-")
		{
			prev_op_low = true;
		}
		answer.push_back(" " + op + " " + to_string(new_x));
	}
	for (const auto& s : answer)
	{
		cout << s;
	}
	cout << endl;
	return (0);
}
