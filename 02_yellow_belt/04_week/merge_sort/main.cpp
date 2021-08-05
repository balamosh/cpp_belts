//#include "merge_sort_div2.cpp"
#include "merge_sort_div3.cpp"

#include <vector>
#include <iostream>

using namespace std;

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
