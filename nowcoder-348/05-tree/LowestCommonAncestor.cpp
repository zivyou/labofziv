#include <iostream>

/**
 * 最低公共祖先：树形Dp
 */

struct Node {
  Node* left;
  Node* right;
  int val;
};

struct Info {
  bool findO1; // 有没有发现O1
  bool findO2; // 有没有发现O2
  Node* findAns; //发现的最低公共祖先节点
  Info(bool f1, bool f2, Node* n) {
    findO1 = f1;
    findO2 = f2;
    findAns = n;
  }
};
class Solution {
private:
public:
  Info process(Node* x, Node* o1, Node* o2) {
    if (x == nullptr) {
      return Info(false, false, nullptr);
    }

    Info leftInfo = process(x->left, o1, o2);
    if (leftInfo.findAns != nullptr) {
      return leftInfo;
    }

    Info rightInfo = process(x->right, o1, o2);
    if (rightInfo.findAns != nullptr) {
      return rightInfo;
    }

    // 左右两棵子树都没有发现最低公共祖先
    if (leftInfo.findO1 && rightInfo.findO2) {
      return Info(true, true, x);
    }

    if (leftInfo.findO2 && rightInfo.findO1) {
      return Info(true, true, x);
    }

    bool isO1 = x == o1;
    bool isO2 = x == o2;
    if (leftInfo.findO1 || rightInfo.findO1) {
      if (isO2) {
        return Info(true, true, x);
      } else {
       return Info(true, false, nullptr);
      }
    }

    if (leftInfo.findO2 || rightInfo.findO2) {
      if (isO1) {
        return Info(true, true, x);
      } else {
        return Info(false, true, x);
      }
    }

    // 左右两棵子树都没有发现o1或o2
    return Info(isO1, isO2, nullptr);
  }
};