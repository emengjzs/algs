#pragma once

#include <vector>

namespace emeng {
namespace agls {

using std::vector;

class QuickUnionUF {
 public:
  explicit QuickUnionUF(int n) : _parent(n), _tree_size(n, 1), _count(n) {
    for (int i = 0; i != n; ++i) {
      _parent[i] = i;
    }
  }

  int find(int p) {
    while (p != _parent[p]) {
      _parent[p] = _parent[_parent[p]];
      p = _parent[p];
    }
    return p;
  }

  int connected(int p, int q) { return find(p) == find(q); }

  void makeUnion(int p, int q) {
    int p_root = find(p);
    int q_root = find(q);
    if (p_root != q_root) {
      if (_tree_size[p] > _tree_size[q]) {
        _parent[q] = p;
        _tree_size[q_root] += _tree_size[q_root];
      } else {
        _parent[p] = q;
        _tree_size[p_root] += _tree_size[q_root];
      }
      --_count;
    }
  }

  int count() { return _count; }

 private:
  int _count;
  vector<int> _parent;
  vector<int> _tree_size;

  // Not copy allowed
  QuickUnionUF(const QuickUnionUF &);
  void operator=(const QuickUnionUF &);
};

}
}