#include <string>
#include <vector>
#include <iostream>
using namespace std;

void	MoveStrings(vector<string>& source, vector<string>& destination);

int	main()
{
	vector<string>	src = {"a", "b", "c"};
	vector<string>	dest = {"z"};

	cout << "source:\n";
	for (auto s : src)
		cout << s << " ";
	cout << endl;
	cout << "destination:\n";
	for (auto s : dest)
		cout << s << " ";
	cout << endl;
	
	MoveStrings(src, dest);
	
	cout << "source:\n";
	for (auto s : src)
		cout << s << " ";
	cout << endl;
	cout << "destination:\n";
	for (auto s : dest)
		cout << s << " ";
	cout << endl;
	return (0);
}
