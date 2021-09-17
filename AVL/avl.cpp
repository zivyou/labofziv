#include <vector>
#include "avl.h"

using namespace std;

int main() {
  vector<int> data = {1, 2, 3, 4, 5, 6, 7};
  avlTree<int> * tree = create<int>(data);
  return 0;
}