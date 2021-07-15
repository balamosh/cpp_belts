#include <iostream>
#include <vector>
#include <map>
using namespace std;

void	Do(void)
{
	static map<vector<string>, int>	bus_routes;
	int	n;
	cin >> n;
	vector<string>	route;
	for (int i = 0; i < n; i++)
	{
		string	stop;
		cin >> stop;
		route.push_back(stop);
	}
	if (bus_routes.count(route))
	{
		cout << "Already exists for " << bus_routes[route] << endl;
	}
	else
	{
		int	new_bus = bus_routes.size() + 1;
		bus_routes[route] = new_bus;
		cout << "New bus " << new_bus << endl;
	}
}

int	main(void)
{
	int	q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		Do();
	}
	cout << endl;
	return (0);
}
