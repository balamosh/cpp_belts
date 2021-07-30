#include <utility>
#include <vector>
#include <map>

using namespace std;

// Prototypes

template<typename T>
T				Sqr(const T& x);

template<typename First, typename Second>
pair<First, Second>		Sqr(const pair<First, Second>& x);

template<typename First, typename Second>
pair<const First, Second>	Sqr(const pair<const First, Second>& x);

template<typename Collection>
Collection			SqrCollection(const Collection& c);

template<typename T>
vector<T>			Sqr(const vector<T>& v);

template<typename Key, typename Value>
map<Key, Value>			Sqr(const map<Key, Value>& m);

// Functions

template<typename T>
T				Sqr(const T& x)
{
	return (x * x);
}

template<typename First, typename Second>
pair<First, Second>		Sqr(const pair<First, Second>& x)
{
	return (make_pair(Sqr(x.first), Sqr(x.second)));
}

template<typename First, typename Second>
pair<const First, Second>	Sqr(const pair<const First, Second>& x)
{
	return (make_pair(x.first, Sqr(x.second)));
}

/*
template<typename Collection>
Collection			SqrCollection(const Collection& c)
{
	Collection	new_c = c;
	for (auto& item : new_c)
	{
		item = Sqr(item);
	}
	return (new_c);
}
*/

template<typename T>
vector<T>			Sqr(const vector<T>& v)
{
	vector<T>	new_v = v;
	for (auto& item : new_v)
	{
		item = Sqr(item);
	}
	return (new_v);
	//return (SqrCollection(v));
}

template<typename Key, typename Value>
map<Key, Value>			Sqr(const map<Key, Value>& m)
{
	map<Key, Value>	new_m = m;
	for (auto& item : new_m)
	{
		item.second = Sqr(item.second);
	}
	return (new_m);
	//return (SqrCollection(m));
}
