//
// Created by zivyou on 2020/12/11.
//

#ifndef UNIONFINDSET_UNIONFINDSET_H
#define UNIONFINDSET_UNIONFINDSET_H

#include <vector>
class UnionFindSet {
private:
  // ranks_代表树的高度
  std::vector<int> ranks_;
  std::vector<int> parents_;
public:
  UnionFindSet(int range);
  int Find(int n);
  bool SameSet(int a, int b);
  bool Union(int a, int b);
  void display();
};


#endif //UNIONFINDSET_UNIONFINDSET_H
