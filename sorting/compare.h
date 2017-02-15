#pragma once

namespace emeng {
namespace algs {
  

  template <typename T>
  struct LessCompare {
    inline int operator()(const T& t1, const T& t2) const {
      return t1 < t2 ? +1 : (t1 > t2 ? -1 : 0);
    }
  };

  template <typename T>
  struct GreaterCompare {
    inline int operator()(const T& t1, const T& t2) const {
      return t1 > t2 ? 1 : (t1 < t2 ? -1 : 0);
    }
  };

  template <typename T>
  inline LessCompare<T> less() {
    static LessCompare<T> cmp;
    return cmp;
  }

  template <typename T>
  inline GreaterCompare<T> greater() {
    static GreaterCompare<T> cmp;
    return cmp;
  }

}  
}