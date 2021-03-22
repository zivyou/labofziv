#include "BinarySearchTree.hpp"


template<typename K, typename V>
class SelfBalancedBinarySearchTree : public BinarySearchTree<K, V> {
private:
  void leftRotate(const Node<K, V>& node) {

  }

  void rightRotate(const Node<K, V>& node) {

  }

  virtual bool isLL(const Node<K, V>& node) {
    if (node.left != nullptr && node.left->left != nullptr && node.left->left->size > node.right->size) {
      return true;
    }
    return false;
  };
  virtual bool isLR(const Node<K, V>& node) {

  }
  virtual bool isRL(const Node<K, V>& node) {

  }
  virtual bool isRR(const Node<K, V>& node) {

  }
public:
  Node<K, V>& selfBalance(const Node<K, V>& node) {
    /**
     * LL（左孩子的左高度较高）：将左孩子右旋
     * RR（右孩子的右高度较高）：将右孩子左旋
     * LR（左孩子的右高度较高）：1。先将左孩子的右孩子左旋；2。再将左孩子右旋
     * RL（右孩子的左高度较高）：1。先将右孩子的左孩子右旋；2。再将右孩子左旋
     */
  }
};