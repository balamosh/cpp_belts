#include <iostream>
#include <vector>
using namespace std;

int Avg(const vector<int>& v)
{
    int sum = 0;
    for (auto x : v)
        sum += x;
    return (sum / v.size());
}

void    PrintVector(const vector<int>& v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int len;
    cin >> len;
    
    vector<int> temp_stat(len);
    for (int i = 0; i < len; i++)
        cin >> temp_stat[i];
    
    int avg = Avg(temp_stat);
    vector<int> answer;
    for(int i = 0; i < temp_stat.size(); i++)
    {
        if (temp_stat[i] > avg)
            answer.push_back(i);
    }

    cout << answer.size() << endl;
    PrintVector(answer);
    
    return (0);
}
