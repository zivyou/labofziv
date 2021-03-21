//
// Created by zivyou on 2021/3/21.
//

#include <iostream>
#include "BinarySearchTree.hpp"

using namespace std;
class MyBinarySearchTree : public BinarySearchTree<int, int> {
private:
  bool rawSelfChecker(const Node<int, int>* root) {
    if (!root) return true;
    if (!(root->left) && !(root->right)) return true;
    const Node<int, int>* successor = BinarySearchTree::successor(*root);
    if (successor->key < root->key) return false;
    const Node<int, int>* predecessor = BinarySearchTree::predecessor(*root);
    if (predecessor->key > root->key) return false;
    if (!(rawSelfChecker(root->left))) return false;
    return rawSelfChecker(root->right);
  }
public:
  bool selfChecker () {
    return rawSelfChecker(root);
  }
};

int main() {
  MyBinarySearchTree bst;
  cout<<bst.selfChecker()<<endl;
  return 0;
}