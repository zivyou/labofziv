#ifndef __AVL_H__
#define __AVL_H__

#include <vector>
#include <iostream>
#include <stack>
#include "../Tree/BinaryTree.hpp"

using namespace std;

/**
 * AVL树：Created by G. M. Adelson & Evgenii Landis, 是一种(绝对)平衡二叉搜索树
 * 任何子树的左子树和右子树的高度差不超过1
 */

/**
 * FIXME:
 * 1. 树的插入属实有点毛病，需要多练习修复下；// 已经修复好了
 * 2. 树高现在是没有存储的，每次通过递归的方法计算，效率太低；
 *
 */

/*
template<typename T>
class avlNode{
public:
    T element;
    avlNode *leftChild;
    avlNode *rightChild;

public:
    avlNode(T e){
        element = e;
        leftChild = nullptr;
        rightChild = nullptr;
    };

    avlNode() {
      leftChild = nullptr;
      rightChild = nullptr;
    }
};
*/

template<typename T>
using avlNode = Node<T>;

template<typename T>
using avlTree = Node<T>;


template<typename T>
avlTree<T>* leftRotate(avlTree<T> *tree){
  avlTree<T> *N1 = tree->rightChild;
  avlTree<T> *N2 = N1->rightChild;
  tree->rightChild = N1->leftChild;
  N1->leftChild = tree;
  return N1;
}

template<typename T>
avlTree<T>* rightRotate(avlTree<T> *tree){
  avlTree<T> *N1 = tree->leftChild;
  avlTree<T> *N2 = N1->leftChild;
  tree->leftChild = N1->rightChild;
  N1->rightChild = tree;
  return N1;
}

/*
 * 这种称为RL型不平衡，需要先右旋然后再左旋
        tree           tree             N2
          \              \             /  \
          N1   =>        N2     =>   tree N1
          /               \
        N2                N1
*/
/**
 * @tparam T
 * @param tree
 */
template<typename T>
avlTree<T>* rebalanceRLType(avlTree<T> *tree) {
  tree->rightChild = rightRotate(tree->rightChild);
  return leftRotate(tree);
}


/*
 * 这种称为RR型，需要通过左旋解决
        tree                N1
          \                / \
          N1     =>     tree N2
           \
           N2
*/
template<typename T>
avlTree<T>* rebalanceRRType(avlTree<T> *tree) {
  return leftRotate(tree);
}


/*
 * 这种称为LR型，需要通过先左旋再右旋解决
        tree            tree              N2
        /                /               /  \
       N1     =>       N2     =>        N1  tree
        \              /
        N2            N1
*/
template<typename T>
avlTree<T>* rebalanceLRType(avlTree<T> *tree) {
  tree->leftChild = leftRotate(tree->leftChild);
  return rightRotate(tree);
}


/*
 * 这种称为LL型，需要通过右旋解决
        tree                  N1    
        /                    /  \
       N1      =>           N2  tree
      /
    N2
*/
template<typename T>
avlTree<T>* rebalanceLLType(avlTree<T> *tree) {
  return rightRotate(tree);
}


template<typename T>
int getBalanceFactor(avlTree<T> *tree){
    if (!tree) return 0;
    return getHeight(tree->leftChild) - getHeight(tree->rightChild);
}


template<typename T>
int getHeight(avlTree<T> *tree){
    if (!tree)
        return 0;
    return max<int>(getHeight(tree->leftChild), getHeight(tree->rightChild))+1;
}

template<typename T>
bool avlBalanced(avlTree<T> *tree){
    int lHeight = getHeight(tree->leftChild);
    int rHeight = getHeight(tree->rightChild);
    if (lHeight - rHeight <= 1 && rHeight - lHeight <= 1)
        return true;
    else
        return false;
}

/**
*   exact balanced
*/
template<typename T>
bool balanced(avlTree<T> *tree){
    if (getHeight(tree->leftChild) == getHeight(tree->rightChild))
        return true;
    else
        return false;
}

template<typename T>
avlTree<T> *balance(avlTree<T> *tree){
    avlTree<T> *re;
    int factor = getBalanceFactor(tree);
    if (factor > 1){
        if (getBalanceFactor(tree->leftChild) > 0){
            // LL
            re = rebalanceLLType<T>(tree);
        }else{
            // LR
            re = rebalanceLRType<T>(tree);
        }
    }else if (factor < -1) {
        if (getBalanceFactor(tree->leftChild) > 0){
            // RL
            re = rebalanceRLType<T>(tree);
        }else{
            // RR
            re = rebalanceRRType<T>(tree);
        }
    }else
        return tree;
    if (!avlBalanced(re))
        return balance(re);
    return re;
};

template<typename T>
void del(avlTree<T> *tree, T element){

};

/**
 * 平衡二叉树的插入过程也是一个O(logn)复杂度的过程
 * 为了保证插入后的树的每一个子树都是平衡的，插入过程需要使用递归的方法实现。
 * 要避免出现只有根节点平衡的树，比如
 *                     3
 *                    /  \
 *                   2    4
 *                 /       \
 *                1         5
 *                           \
 *                            6
 * 避免的方法就是再插入的过程中随时调整树的平衡。
 * 本质上来说，每次的插入过程都有可能导致左右两边的不平衡。这样需要自下而上的调整树的平衡性。
 * 如何'自下而上'地调整树的平衡性呢？两种方法，一种是递归，一种是用栈记录创建过程中的插入路线
 * @tparam T
 * @param tree
 * @param element
 * @return
 */
template<typename T>
avlTree<T> *insert(avlTree<T> *&tree, T element){
  avlTree<T>* newNode = new avlTree<T>(element);
  if (!tree) {
    tree = newNode;
    return newNode;
  };

  avlTree<T>* t = tree;
  avlTree<T>* parent = nullptr;
  std::stack<avlNode<T>*> st;
  while (t) {
    // 记录住树中这个元素的搜索路径
    if (t->element == element) {
      return tree; // 已经有这个元素，什么都不需要做，直接返回就行
    }
    st.push(t); // 记录路径
    parent = t;
    if (t->element < element) {
      // 向右走
      t = t->rightChild;
    } else {
      // 向左走
      t = t->leftChild;
    }
  }

  if (element > parent->element) {
    // 搜索的时候，发现这个数应该是插入到最后搜索的节点的右孩子节点
    parent->rightChild = newNode;
  } else {
    // 搜索的时候，发现这个数应该是插入到最后搜索的节点的左孩子节点
    parent->leftChild = newNode;
  }

  // 开始回溯搜索的路径，自下而上的调整树的平衡性
  avlNode<T>* re = nullptr;
  while (!st.empty()) {
    avlNode<T>* n = st.top();
    st.pop();
    // 属实写的不太优雅。这里为了用我们设计好的balance()，这个balance()的调用很奇特，需要用他的父亲来接收返回值，所以写的比较丑陋
    avlNode<T>* parent2 = nullptr;
    if (!st.empty()) parent2 = st.top();
    if (parent2) {
      if (parent2->leftChild == n) {
        parent2->leftChild = balance(n);
      } else {
        parent2->rightChild = balance(n);
      }
      re = parent2;
    } else {
      re = balance(tree);
    }
  }
  return re;
};

template<typename T>
avlTree<T> *create(vector<T> tree){

  avlTree<T> *re = nullptr;
  for (T n:tree) {
    re = insert<T>(re, n);
  }
  return balance(re);
}


template<typename T>
avlTree<T> *update(avlTree<T> *tree, T element){

};

template<typename T>
avlTree<T> *search(avlTree<T> *tree, T element){
    avlTree<T> *t = tree;
    if ((t->element > element)){
        t = t->leftChild;
    } else if ((t->element == element)){
        return t;
    } else{
        t = t->rightChild;
    }

    return nullptr;
};

template<typename T>
void display(avlTree<T>* root) {
  if (!root) return;
  if (root->leftChild)
    print(root->leftChild);
  std::cout<<root->element<<" ";
  if (root->rightChild)
    print(root->rightChild);
}

#endif
