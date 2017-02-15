// Take care of!!
// header (once, stdlibheader, own header)
// namespace
// template 
// class
// public private
// ctr, dtr, cpctr
// const inline

#pragma once

#include <iostream>
#include <vector>
#include <utility>

#include "compare.h"

namespace emeng {
namespace algs {
  
  // like <T, Compare<T>> in Java
  template<typename T, template <typename> class Compare>
  void selection_sort(std::vector<T>& arr, const Compare<T>& cmp) {
    for (int i = 0; i != arr.size(); ++ i) {
      int max_index = i;
      for (int j = i; j != arr.size(); ++ j) {
        if (cmp(arr[i], arr[j]) < 0) {
          max_index = j;
        }
      }
      if (max_index != i) {
        std::swap(arr[max_index], arr[i]);
      }
    }
  }
  
  template<typename T, template<typename> class Compare>
  void insertion_sort(std::vector<T>& arr, const Compare<T>& cmp) {
    // Check if it is sorted.
    bool sorted = true;
    for (int i = arr.size() - 1; i > 0; -- i) {
      if (cmp(arr[i], arr[i - 1]) > 0) {
        std::swap(arr[i], arr[i - 1]);
        sorted = false;
      }
    }
    if (sorted) return;
    
    // Original insertion sort, notice the i is begin from 1, not 0!
    for (int i = 1; i < arr.size(); ++ i) {
      T temp = arr[i];
      int j = i - 1;
      // Don't have to check if j is out of bound.
      while (cmp(temp, arr[j]) > 0) {
        arr[j + 1] = arr[j];
        -- j;
      }
      // Notice that the index we put temp in is j + 1, not j ! 
      // When a variable breaks from while/for, the value is already invalid
      arr[j + 1] = temp;
    }
  }
  
  
  
}
}

