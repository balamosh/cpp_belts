#include <vector>
#include <iostream>
using namespace std;

vector<int>	Reversed(const vector<int>& v);

int main()
{
    vector<int> nums = {1, 5, 3, 4, 2};
    vector<int> nums_rev;

    cout << "orig:\n";
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    nums_rev = Reversed(nums);

    cout << "reversed:\n";
    for (auto n : nums_rev)
        cout << n << " ";
    cout << endl;
}
