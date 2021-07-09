#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Add(vector<vector<string>>& concerns, int i, string s)
{
    concerns[i - 1].push_back(s);
}

void Dump(const vector<vector<string>>& concerns, int i)
{
    cout << concerns[i - 1].size() << ' ';
    for (const auto& item : concerns[i - 1])
        cout << item << ' ';
    cout << endl;
}

void Next(vector<vector<string>>& concerns, int days)
{
    vector<vector<string>> new_concerns(days);

    for (int i = 0, j = 0; i < concerns.size(); i++)
    {
        new_concerns[j].insert(end(new_concerns[j]), begin(concerns[i]), end(concerns[i]));
        if (j < days - 1)
            j++;
    }
    concerns.clear();
    concerns = new_concerns;
}

void NextMonth(int& month, const vector<int>& days_in_month)
{
    if (month == days_in_month.size() - 1)
        month = 0;
    else
        month++;
}

int main()
{
    int op_amount;
    cin >> op_amount;

    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = 0;
    vector<vector<string>> concerns(days_in_month[month]);
    for (int i = 0; i < op_amount; i++)
    {
        string op;
        cin >> op;
        if (op == "ADD")
        {
            int i;
            string s;
            cin >> i >> s;
            Add(concerns, i, s);
        }
        else if (op == "DUMP")
        {
            int i;
            cin >> i;
            Dump(concerns, i);
        }
        else if (op == "NEXT")
        {
            NextMonth(month, days_in_month);
            Next(concerns, days_in_month[month]);
        }
    }

    return (1);
}
