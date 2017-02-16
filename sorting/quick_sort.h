#pragma once

#include <vector>
#include <utility>
#include <iostream>

#include "compare.h"

namespace emeng {
namespace algs {

template <typename T, template <typename> class Compare>
inline void quick_sort(std::vector<T>& arr, const Compare<T>& cmp) {
  quick_sort(arr, cmp, 0, arr.size() - 1);
}

template <typename T, template <typename> class Compare>
void quick_sort(std::vector<T>& arr, const Compare<T>& cmp, int low, int high) {
  // At least there are two elements
  if (low < high) {
    int pivot_index = _partition(arr, cmp, low, high);
    quick_sort(arr, cmp, low, pivot_index - 1);
    quick_sort(arr, cmp, pivot_index + 1, high);
  }
}

template <typename T, template <typename> class Compare>
int _partition(std::vector<T>& arr, const Compare<T>& cmp, int low, int high) {
  T& pivot = arr[low];
  int i = low + 1, j = high;
  while (i < j) {
    // Not 'i < j' because j may be invalid after breaking from loop
    while (i < high && cmp(arr[i], pivot) < 0) ++ i;
    // Not 'j < i' because j may be invalid after breaking from loop
    while (j > low && cmp(arr[j], pivot) > 0) -- j;
    if (i < j) {
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[low], arr[j]);
  return j;
}


}
}