#include <iostream>
#include <list>
#include <map>

using namespace std;

class Athlets {
public:
	void	Add(int val, int before) {
		if (val_to_pos.count(before)) {
			val_to_pos[val] = values.insert(val_to_pos[before], val);
		}
		else {
			values.push_back(val);
			val_to_pos[val] = --values.end();
		}
	}

	void	Print() {
		for (auto x : values) {
			cout << x << '\n';
		}
	}
private:
	map<int, list<int>::iterator>	val_to_pos;
	list<int>						values;
};

int	main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Athlets	manager;
	
	int	n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int	val, before;
		cin >> val >> before;
		manager.Add(val, before);
	}
	manager.Print();

	return (0);
}