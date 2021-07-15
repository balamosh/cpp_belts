#include <iostream>
#include <vector>
#include <map>
using namespace std;

void	NewBus(map<string, vector<string>>& busses, map<string, vector<string>>& stops)
{
	string	bus;
	cin >> bus;
	int	stop_count;
	cin >> stop_count;
	for (int i = 0; i < stop_count; i++)
	{
		string	stop;
		cin >> stop;
		busses[bus].push_back(stop);
		stops[stop].push_back(bus);
	}
}

void	BussesForStop(map<string, vector<string>>& busses, map<string, vector<string>>& stops)
{
	string	stop;
	cin >> stop;
	if (stops.count(stop) == 0)
	{
		cout << "No stop" << endl;
		return ;
	}
	int	len = stops[stop].size();
	int	i = 0;
	for (auto bus : stops[stop])
	{
		cout << bus;
		if (i < len - 1)
			cout << " ";
		i++;
	}
	cout << endl;
}

void	StopsForBus(map<string, vector<string>>& busses, map<string, vector<string>>& stops)
{
	string	bus;
	cin >> bus;
	if (busses.count(bus) == 0)
	{
		cout << "No bus" << endl;
		return ;
	}
	for (auto stop : busses[bus])
	{
		cout << "Stop " << stop << ": ";
		int	i = 0;
		int	len = stops[stop].size();
		if (len == 1)
			cout << "no interchange";
		else
		{
			for (auto b : stops[stop])
			{
				if (b != bus)
				{
					cout << b;
					i++;
				}
				if (i < len - 1)
					cout << " ";
			}
		}
		cout << endl;
	}
}

void	AllBusses(map<string, vector<string>>& busses, map<string, vector<string>>& stops)
{
	if (busses.size() == 0)
	{
		cout << "No buses" << endl;
		return ;
	}
	for (auto bus : busses)
	{
		int	i = 0;
		int	len = bus.second.size();
		cout << "Bus " << bus.first << ": ";
		for (auto stop : bus.second)
		{
			cout << stop;
			if (i < len - 1)
				cout << " ";
			i++;
		}
		cout << endl;
	}
}

void	Do(string op)
{
	static map<string, vector<string>>	busses;
	static map<string, vector<string>>	stops;
	if (op == "NEW_BUS")
		NewBus(busses, stops);
	else if (op == "BUSES_FOR_STOP")
		BussesForStop(busses, stops);
	else if (op == "STOPS_FOR_BUS")
		StopsForBus(busses, stops);
	else if (op == "ALL_BUSES")
		AllBusses(busses, stops);
}

int	main(void)
{
	int	q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string	op;
		cin >> op;
		Do(op);
	}
	return (0);
}
