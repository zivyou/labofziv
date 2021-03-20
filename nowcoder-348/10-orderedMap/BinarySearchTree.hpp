
template<typename T>
struct Node {
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;
  int height;
  T value;
};

template<typename T>
class BinarySearchTree {
private:
  Node<T>* root;
  int size;
public:
  Node<T>& search(T t) {
    // 查找
  }

  void add(T t) {

  }

  Node<T>* remove(T t) {
    // 删除
    /* 若是叶子节点，直接删除；若有左无右，让左孩子替代自己；若有右无左，让右孩子替代自己；
     * 若既有左孩子，又有右孩子，可以让自己的后继替代自己
     * */
  }

  Node<T>& successor(const Node& node) {
    /**
     * 1. 无右孩子；2。有右孩子，且右孩子无左孩子； 3。有右孩子，且右孩子有左孩子
     */
  }
};