#include <vector>
#include "avl.h"

using namespace std;

int main() {
  vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 13, 15, 16};
  avlTree<int> * tree = create<int>(data);
  tree->display();
  cout<<"--------------end------------"<<endl;
  return 0;
}