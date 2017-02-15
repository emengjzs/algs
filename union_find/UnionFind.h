#pragma once

template <typename UFImpt>
class UnionFind {
 public:
  UnionFind(int n) : inner_(n) {}

  void makeUnion(int p, int q) { inner_.makeUnion(p, q); }

  int find(int p) { return inner_.find(p); }

  bool connected(int p, int q) { return inner_.connected(p, q); }

  int count() { return inner_.count(); }

 private:
  // inner_ impl
  UFImpt inner_;

  void operator=(const UnionFind &);
  UnionFind(const UnionFind &);
};