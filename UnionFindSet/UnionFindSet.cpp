//
// Created by zivyou on 2020/12/11.
//

#include <iostream>
#include "UnionFindSet.h"

UnionFindSet::UnionFindSet(int range) {
  for (int i=0; i<=range; i++) {
    parents_.push_back(i);
    ranks_.push_back(0);
  }
};

int UnionFindSet::Find(int n) {
  int i = n;
  while (i != parents_[i]) {
    int p = parents_[i];
    i = p;
  }

  parents_[n] = i;
  if (i != n)
    ranks_[n] = ranks_[i]+1;
  return i;
}

bool UnionFindSet::Union(int a, int b) {
  int pa = Find(a);
  int pb = Find(b);
  if (pa == pb) return false;
  if (ranks_[pa] == ranks_[pb]) {
    parents_[pa] = pb;
    ranks_[pa]++;
    return true;
  } else if (ranks_[pa] < ranks_[pb]) {
    parents_[pa] = pb;
    return true;
  } else {
    parents_[pb] = pa;
    return true;
  }
}

void UnionFindSet::display() {
  for (int i=0; i<parents_.size(); i++) std::cout<<i<<", ";
  std::cout<<std::endl;
  for (int i=0; i<parents_.size(); i++) std::cout<<Find(i)<<", ";
  std::cout<<std::endl;
}
