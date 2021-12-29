#include "test_runner.h"
#include "profile.h"

#include <map>
#include <string>
#include <future>
using namespace std;

// Реализуйте шаблон класса Paginator

template <typename Iterator>
class Page {
private:
	Iterator	first, last;
	size_t		size_;
public:
	Page(Iterator f, Iterator l)
	: first(f)
	, last(l)
	, size_(distance(f, l))
	{}

	Iterator	begin() const {
		return (first);
	}
	Iterator	end() const {
		return (last);
	}
	size_t		size() const {
		return (size_);
	}
};

template <typename Iterator>
class Paginator {
private:
	vector<Page<Iterator>>	pages;
public:
	Paginator(Iterator begin, Iterator end, size_t page_size) {
		for (size_t left = distance(begin, end); left > 0; ) {
			size_t current_page_size = min(page_size, left);
			Iterator current_page_end = next(begin, current_page_size);
			pages.push_back({begin, current_page_end});
			left -= current_page_size;
			begin = current_page_end;
    	}
	}

	auto	begin() const {
		return (pages.begin());
	}
	auto	end() const {
		return (pages.end());
	}
	size_t	size() const {
		return (pages.size());
	}
};

template <typename C>
auto	Paginate(C& c, size_t page_size) {
  // Реализуйте этот шаблон функции
  return (Paginator(c.begin(), c.end(), page_size));
}

struct Stats {
  map<string, int> word_frequences;

  void operator += (const Stats& other) {
	  for (const auto& [key, val] : other.word_frequences) {
		  word_frequences[key] += val;
	  }
  }
};

template <typename ContainerOfVectors>
Stats	ExploreKeyWordsSingleThread(ContainerOfVectors& strs) {
	Stats	result;
	for (auto& word : strs) {
		++result.word_frequences[move(word)];
	}
	return (result);
}

Stats ExploreKeyWords(const set<string>& key_words, istream& input) {
  // Реализуйте эту функцию
	vector<future<Stats>>	futures;
	Stats					result;
	vector<string>			strs;
	string	s;
	while (input >> s) {
		if (key_words.count(s)) {
			strs.push_back(move(s));
		}
	}
	for (auto page : Paginate(strs, max(size_t(1), strs.size() / 32))) {
		futures.push_back(async([=] {
			return (ExploreKeyWordsSingleThread(page));
		}));
	}
	for (auto& f : futures) {
		result += f.get();
	}
	return (result);
}

void TestBasic() {
  const set<string> key_words = {"yangle", "rocks", "sucks", "all"};

  stringstream ss;
	ss << "this new yangle service really rocks\n";
	ss << "It sucks when yangle isn't available\n";
	ss << "10 reasons why yangle is the best IT company\n";
	ss << "yangle rocks others suck\n";
	ss << "Goondex really sucks, but yangle rocks. Use yangle\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
    {"yangle", 6},
    {"rocks", 2},
    {"sucks", 1}
  };
  ASSERT_EQUAL(stats.word_frequences, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestBasic);
}
