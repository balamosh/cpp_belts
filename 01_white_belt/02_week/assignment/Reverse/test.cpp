#include <vector>
#include <iostream>
using namespace std;

void	Reverse(vector<int>& v);

int main()
{
    vector<int> nums = {1, 5, 3, 4, 2};

    cout << "orig:\n";
    for (auto n : nums)
        cout << n << " ";
    cout << endl;

    Reverse(nums);

    cout << "reversed:\n";
    for (auto n : nums)
        cout << n << " ";
    cout << endl;
}
