#include <map>

using namespace std;

template<typename Key, typename Value>
Value&	GetRefStrict(map<Key, Value>& m, Key k)
{
	if (m.count(k) == 0)
		throw runtime_error("No value with this key");
	return (m[k]);
}
