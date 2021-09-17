#include <iostream>

using namespace std;

struct Node {
  Node* left;
  Node* right;
  int value;
  Node(int val = 0): value(val) {
    left = nullptr;
    right = nullptr;
  }
};

class MorrisOrder {
private:
  struct Node* root;

public:
  void morrisOrder() {
    Node* cur = root;

    while (cur) {
      if (cur->left) {
        // 如果有左孩子，则先去找左孩子的最右节点
        Node* node = cur->left;
        while (node->right && node != cur /*因为我们后面可能会将叶子节点的右指针改成cur*/) {
          node = node->right;
        }
        if (node->right == nullptr) {
          node->right = cur; // 改一下cur左孩子最右节点的right，让其指向cur
          cur = cur->left;
          continue;
        } else {
          // 说明是第二次来到node了。要恢复一下node->right。
          // 同时让遍历过程回到cur。即cur=cur->right；不过这个过程和下面的cur=cur->right合在一起了
          node->right = nullptr;
        }
      }
      cur = cur->right;
    }
  }
};

int main() {
  Node node = 3;
  std::cout<<(node.value == 2)<<std::endl;
  return 0;
}