#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int>    BuildCharCounters(const string& word)
{
    map<char, int> counters;
    for (const auto& c : word)
        ++counters[c];
    return (counters);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string w1, w2;
        cin >> w1 >> w2;
        if(BuildCharCounters(w1) == BuildCharCounters(w2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0);
}
