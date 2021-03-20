#include "BinarySearchTree.hpp"

template<typename T>
class SelfBalancedBinarySearchTree : public BinarySearchTree<T> {
private:
  void leftRotate(const Node& node) {

  }

  void rightRotate(const Node& node) {

  }
public:
  void selfBalance(const Node& node) {
    /**
     * LL（左孩子的左高度较高）：将左孩子右旋
     * RR（右孩子的右高度较高）：将右孩子左旋
     * LR（左孩子的右高度较高）：1。先将左孩子的右孩子左旋；2。再将左孩子右旋
     * RL（右孩子的左高度较高）：1。先将右孩子的左孩子右旋；2。再将右孩子左旋
     */
  }
};