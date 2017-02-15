#include <vector>
#include <iostream>

#include "sorting/sort.h"

int main() {
  using namespace emeng;
  using namespace std;

  vector<int> arr{ 5, 4, 3, 2, 1 };
  algs::selection_sort(arr, algs::less<int>());
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}