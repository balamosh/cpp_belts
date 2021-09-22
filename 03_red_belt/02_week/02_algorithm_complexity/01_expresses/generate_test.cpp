#include "profile.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define MAX_RAND 1'000'000'000

int main() {
  int	query_count;
  cin >> query_count;

  cout << query_count * 2 << '\n';
  srand(time(NULL));
  {
	for (int i = 0; i < query_count; ++i) {
		int	i1, i2;
		i1 = rand() % (2 * MAX_RAND) - MAX_RAND;
		i2 = rand() % (2 * MAX_RAND) - MAX_RAND;
		cout << "ADD " << i1 << ' ' << i2 << '\n';
	}
  }

  {
	  for (int i = 0; i < query_count; ++i) {
		int	i1, i2;
		i1 = rand() % (2 * MAX_RAND) - MAX_RAND;
		i2 = rand() % (2 * MAX_RAND) - MAX_RAND;
		cout << "GO " << i1 << ' ' << i2 << '\n';
	  }
  }

  return 0;
}
