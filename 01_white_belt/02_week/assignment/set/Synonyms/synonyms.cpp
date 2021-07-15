#include <iostream>
#include <map>
#include <set>
using namespace std;

void	Add(map<string, set<string>>& synonyms)
{
	string	word1, word2;
	cin >> word1 >> word2;
	synonyms[word1].insert(word2);
	synonyms[word2].insert(word1);
}

void	Count(const map<string, set<string>>& synonyms)
{
	string	word;
	cin >> word;
	if (synonyms.count(word) == 0)
		cout << '0' << endl;
	else
		cout << synonyms.at(word).size() << endl;
}

void	Check(const map<string, set<string>>& synonyms)
{
	string	word1, word2;
	cin >> word1 >> word2;
	if (synonyms.count(word1) == 0 ||
		synonyms.count(word2) == 0)
	{
		cout << "NO" << endl;
	}
	else if (synonyms.at(word1).count(word2) ||
		synonyms.at(word2).count(word1))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}

void	Do(string op)
{
	static map<string, set<string>>	synonyms;
	if (op == "ADD")
		Add(synonyms);
	else if (op == "COUNT")
		Count(synonyms);
	else if (op == "CHECK")
		Check(synonyms);
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
	cout << endl;
	return (0);
}
