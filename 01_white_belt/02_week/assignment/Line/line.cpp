#include <iostream>
#include <vector>
#include <string>
using namespace std;

int WorryCount(vector<bool> v)
{
    int counter = 0;
    for (const auto& item : v)
    {
        if (item)
            counter++;
    }
    return (counter);
}

int main()
{
    int op_len;
    cin >> op_len;

    vector<bool> line;
    for (int i = 0; i < op_len; i++)
    {
        string op;
        cin >> op;
        if (op == "WORRY")
        {
            int j;
            cin >> j;
            line[j] = true;
        }
        else if (op == "QUIET")
        {
            int j;
            cin >> j;
            line[j] = false;
        }
        else if (op == "COME")
        {
            int k;
            cin >> k;
            line.resize(line.size() + k, false);
        }
        else if (op == "WORRY_COUNT")
        {
            int wc = WorryCount(line);
            cout << wc << endl;
        }
    }
}
