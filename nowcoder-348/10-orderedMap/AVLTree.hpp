#include "SelfBalancedBinarySearchTree.hpp"

template<typename K, typename V>
class AVLTree : public SelfBalancedBinarySearchTree<K, V> {
private:

public:
  void add(const Node<K, V>& node) {
    BinarySearchTree<K, V>::add(node);
    SelfBalancedBinarySearchTree<K, V>::selfBalance(node);
  }
  void remove(Node<K, V>& node) {
    BinarySearchTree<K, V>::remove(node);
    SelfBalancedBinarySearchTree<K, V>::selfBalance(node);
  }


};