#include <iostream>
#include <vector>

#include "sorting/elementory_sort.h"
#include "sorting/quick_sort.h"

int main() {
  using namespace emeng;
  using namespace std;

  vector<int> arr{5, 67, 3434, 2, 45, 672, 467, 945};
  algs::insertion_sort(arr, algs::less<int>());
  for (const auto& item : arr) {
    cout << item << " ";
  }
  cout << endl;

  vector<int> arr2{5, 67, 3434, 2, 45, 672, 467, 945};
  algs::quick_sort(arr2, algs::greater<int>());
  for (const auto& item : arr2) {
    cout << item << " ";
  }
  cout << endl;

  vector<vector<int>> test_cases = {{},
                                    {0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 2, 3},
                                    {3, 2, 1},
                                    {2, 1, 3},
                                    {4, 4, 4, 4, 5, 4, 4},
                                    {9, 8, 7, 5, 4, 3, 2, 1},
                                    {1, 2, 3, 4, 5, 6, 7, 8},
                                    {3, 2, 3, 2, 3, 2, 3, 2},
                                    {5, 67, 3434, 2, 45, 672, 467, 945}};

  for (auto& arr3 : test_cases) {
    algs::three_way_quick_sort(arr3, algs::greater<int>());
    for (const auto& item : arr3) {
      cout << item << " ";
    }
    cout << endl;
  }

  return 0;
}