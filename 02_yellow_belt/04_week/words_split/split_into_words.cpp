#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>	SplitIntoWords(const string& s)
{
	vector<string>	answer;
	auto		word_begin = begin(s);
	while (word_begin != end(s))
	{
		auto	word_end = find(word_begin, end(s), ' ');
		string	new_word(word_begin, word_end);
		answer.push_back(new_word);
		if (word_end != end(s))
			word_end++;
		word_begin = word_end;
	}
	return (answer);
}
