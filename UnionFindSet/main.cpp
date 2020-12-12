#include <iostream>
#include "UnionFindSet.h"

int main() {
  std::cout << "Hello, World!" << std::endl;
  UnionFindSet ufs(5);
  ufs.Union(0, 1);
  ufs.Union(2, 3);
  ufs.Union(3, 4);
  ufs.display();
  return 0;
}
