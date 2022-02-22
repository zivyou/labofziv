#include <iostream>
#include <vector>
#include <stack>

#include "../../../Tree/BinaryTree.hpp"

class TreeNode: Node<int> {
public:
  int val;
  TreeNode *right;
  TreeNode *left;
  TreeNode() : val(0), left(nullptr), right(nullptr), Node<int>(0) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), Node<int>(0){
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), Node<int>(x) {
  }
};

class BSTIterator {
private:
  std::vector<TreeNode*> data;
  int counts;
  int index;
public:
  BSTIterator(TreeNode* root) {
    counts = 0;
    index = 0;
    // 左中右
    TreeNode* cur = root;
    std::stack<TreeNode*> path;
    while (cur || !path.empty()) {
      while (cur->left) {
        path.push(cur);
        cur=cur->left;
      }
      data.push_back(cur);
      counts++;
      if (!path.empty()) {
        cur = path.top();
        path.pop();
        cur = cur->right;
      }
    }
  }

  int next() {
    return data[index++]->val;
  }

  bool hasNext() {
    return index<=counts;
  }
};

int main() {

}