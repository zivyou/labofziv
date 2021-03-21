#include <vector>

template<typename K, typename V>
struct Node {
  Node<K, V>* left;
  Node<K, V>* right;
  Node<K, V>* parent;
  int height;
  K key;
  V value;
};

template<typename K, typename V>
class BinarySearchTree {
private:
  Node<K, V>* root;
  int size;
public:
  Node<K, V>& search(K t) {
    // 查找
  }

  void add(K t) {

  }

  Node<K, V>* remove(K t) {
    // 删除
    /* 若是叶子节点，直接删除；若有左无右，让左孩子替代自己；若有右无左，让右孩子替代自己；
     * 若既有左孩子，又有右孩子，可以让自己的后继替代自己
     * */
  }

  Node<K, V>& successor(const Node<K, V>& node) {
    /**
     * 1. 无右孩子；2。有右孩子，且右孩子无左孩子； 3。有右孩子，且右孩子有左孩子
     */
  }
};