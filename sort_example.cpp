#include <vector>
#include <iostream>

#include "sorting/elementory_sort.h"

int main() {
  using namespace emeng;
  using namespace std;

  vector<int> arr{ 5, 67, 3434, 2, 45, 672, 467, 945 };
  algs::insertion_sort(arr, algs::greater<int>());
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << endl;
  return 0;
}