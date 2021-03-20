#include "SelfBalancedBinarySearchTree.hpp"

template<typename T>
class AVLTree : public SelfBalancedBinarySearchTree<T> {
private:

public:
  void add(Node<T>& node) {
    BinarySearchTree<T>::add(node);
    SelfBalancedBinarySearchTree<T>::selfBalance(node);
  }
  void remove(Node<T>& node) {
    BinarySearchTree<T>::remove(node);
    SelfBalancedBinarySearchTree<T>::selfBalance(node);
  }

  
};