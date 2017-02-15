#include <iostream>

#include "union_find/QuickFindUF.h"
#include "union_find/QuickUnionUF.h"
#include "union_find/UnionFind.h"

using std::cout;
using std::endl;
using namespace emeng::agls;

int main() {
  UnionFind<QuickUnionUF> uf(5);
  cout << uf.count() << endl;
  return 0;
}