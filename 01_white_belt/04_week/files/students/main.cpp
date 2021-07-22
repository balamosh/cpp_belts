#include <iostream>
#include <vector>
using namespace std;

struct Student
{
	struct Date
	{
		int	day;
		int	month;
		int	year;
	};

	string	name;
	string	surname;
	Date	birth;
};

int	main(void)
{
	int	n;
	cin >> n;
	vector<Student>	students(n);
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name
			>> students[i].surname
			>> students[i].birth.day
			>> students[i].birth.month
			>> students[i].birth.year;
	}
	int	m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string	op;
		int	k;
		cin >> op >> k;
		k--;
		if (k >= n || k < 0)
			cout << "bad request" << endl;
		else if (op == "name")
		{
			cout << students[k].name << ' ' << students[k].surname << endl;
		}
		else if (op == "date")
		{
			cout << students[k].birth.day << '.'
				<< students[k].birth.month << '.'
				<< students[k].birth.year << endl;
		}
		else
			cout << "bad request" << endl;
	}
	return (0);
}
