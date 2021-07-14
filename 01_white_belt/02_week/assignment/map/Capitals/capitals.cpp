#include <iostream>
#include <map>
using namespace std;

void	ChangeCap(map<string, string>& capitals)
{
	string	country, new_capital;
	cin >> country >> new_capital;
	if (capitals.count(country) == 0)
	{
		cout << "Introduce new country " 
			<< country 
			<< " with capital " 
			<< new_capital << endl;
		capitals[country] = new_capital;
	}
	else if (capitals[country] == new_capital)
	{
		cout << "Country " 
			<< country
			<< " hasn't changed its capital" << endl;
	}
	else
	{
		cout << "Country "
			<< country
			<< " has changed its capital from "
			<< capitals[country]
			<< " to "
			<< new_capital << endl;
		capitals[country] = new_capital;
	}
}

void	Rename(map<string, string>& capitals)
{
	string	old_country, new_country;
	cin >> old_country >> new_country;
	if (old_country == new_country ||
		capitals.count(old_country) == 0 ||
		capitals.count(new_country) == 1)
	{
		cout << "Incorrect rename, skip" << endl;
	}
	else
	{
		cout << "Country "
			<< old_country
			<< " with capital "
			<< capitals[old_country]
			<< " has been renamed to "
			<< new_country << endl;
		capitals[new_country] = capitals[old_country];
		capitals.erase(old_country);
	}
}

void	About(map<string, string>& capitals)
{
	string	country;
	cin >> country;
	if (capitals.count(country) == 0)
	{
		cout << "Country "
			<< country
			<< " doesn't exist" << endl;
	}
	else
	{
		cout << "Country "
			<< country
			<< " has capital "
			<< capitals[country] << endl;
	}
}

void	Dump(map<string, string>& capitals)
{
	int	len = capitals.size();
	if (len == 0)
	{
		cout << "There are no countries in the world";
	}
	else
	{
		int	i = 0;
		for (auto country : capitals)
		{
			cout << country.first << "/" << country.second;
			if (i < len - 1)
				cout << " ";
			i++;
		}
	}
	cout << endl;
}

void	Do(string op)
{
	static map<string, string>	capitals;
	if (op == "CHANGE_CAPITAL")
		ChangeCap(capitals);
	if (op == "RENAME")
		Rename(capitals);
	if (op == "ABOUT")
		About(capitals);
	if (op == "DUMP")
		Dump(capitals);
}

int	main(void)
{
	int	n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string	op;
		cin >> op;
		Do(op);
	}
	cout << endl;
	return (0);
}
