#include "profile.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int query_count;
  cin >> query_count;
  cout << query_count * 2 << '\n';

  vector<int>	users;
  {
    for (int i = 0; i < query_count; ++i) {
		int	user_id = rand() % 100'000 + 1;
		cout << "READ " << user_id << ' ' << user_id % 5 + i * 900 / query_count << '\n';
		users.push_back(user_id);
	}
  }
  {
    for (const auto& id : users) {
		cout << "CHEER " << id << '\n';
	}
  }

  return 0;
}