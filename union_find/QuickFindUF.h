#pragma once

#include <vector>

using std::vector;

namespace emeng {
namespace algs {


class QuickFindUF {

public:
  explicit QuickFindUF(int n) : arr_(n), count_(n) {
    for (int i = 0; i != arr_.size(); ++i) {
      arr_[i] = i;
    }
  }

  void makeUnion(int p, int q) {
    if (validate(p) && validate(q)) {
      int p_id = arr_[p];
      int q_id = arr_[q];
      if (p_id != q_id) {
        for (auto &item : arr_) {
          if (item == p_id) {
            item = q_id;
          }
        }
        --count_;
      }
    }
  }

  int find(int p) { return validate(p) ? arr_[p] : -1; }

  bool connected(int p, int q) { return arr_[p] == arr_[q]; }

  int count() { return count_; }

private:
  bool validate(int i) { return i > 0 && i < arr_.size(); }
  vector<int> arr_;
  int count_;
  
  QuickFindUF(const QuickFindUF&);
  void operator=(const QuickFindUF&);
};

}
}