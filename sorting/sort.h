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
  
  template<typename T>
  struct LessCompare {
    inline int operator()(const T& t1, const T& t2) const {
      return t1 < t2 ? +1 : (t1 > t2 ? -1 : 0);
    }
  };
  
  template<typename T>
  struct GreaterCompare {
    inline int operator()(const T& t1, const T& t2) const {
      return t1 > t2 ? 1 : (t1 < t2 ? -1 : 0); 
    }
  };
  
  template<typename T>
  inline LessCompare<T> less() {
    LessCompare<T> cmp;
    return cmp;
  }
  
  template<typename T>
  inline GreaterCompare<T> greater() {
    GreaterCompare<T> cmp;
    reutrn cmp;
  }
  
}
}

