#ifndef __AVL_H__
#define __AVL_H__

#include <vector>

using namespace std;

/**
 * AVL树：Created by G. M. Adelson & Evgenii Landis, 是一种(绝对)平衡二叉搜索树
 */

template<typename T>
class avlNode{
    T element;
    avlNode *leftChild;
    avlNode *rightChild;

public:
    avlNode(T e){
        element = e;
        leftChild = nullptr;
        rightChild = nullptr;
    };
};

template<typename T>
using avlTree = avlNode<T>;

/*
        tree           tree             N2
          \              \             /  \
          N1   =>        N2     =>   tree N1
          /               \
        N2                N1
*/
template<typename T>
void rightLeftRotation(avlTree<T> *tree){
    avlTree<T> *N1 = tree->rightChild;
    avlTree<T> *N2 = N1->leftChild;
    tree->rightChild = N2;
    N1->leftChild = N2->rightChild;
    N2->rightChild = N1;
    return rightRightRotation(tree);
}


/*
        tree                N1
          \                / \
          N1     =>     tree N2
           \
           N2
*/
template<typename T>
void rightRightRotation(avlTree<T> *tree){
    avlTree<T> *N1 = tree->rightChild;
    avlTree<T> *N2 = N1->rightChild;
    tree->rightChild = N1->leftChild;
    N1->leftChild = tree;
    return N1;
}


/*
        tree            tree              N2
        /                /               /  \
       N1     =>       N2     =>        N1  tree
        \              /
        N2            N1
*/
template<typename T>
void leftRightRotation(avlTree<T> *tree){
    avlTree<T> *N1 = tree->leftChild;
    avlTree<T> *N2 = N1->rightChild;
    tree->leftChild = N2;
    N1->rightChild = N2->leftChild;
    N2->leftChild = N1;
    return leftLeftRotation(tree);
}


/*
        tree                  N1    
        /                    /  \
       N1      =>           N2  tree
      /
    N2
*/
template<typename T>
void leftLeftRotation(avlTree<T> *tree){
    avlTree<T> *N1 = tree->leftChild;
    tree->leftChild = N1->rightChild;
    N1->rightChild = tree;
    return N1;
}

template<typename T>
int getBalanceFactor(avlTree<T> *tree){
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
            re = leftLeftRotation(tree);
        }else{
            // LR
            re = leftRightRotation(tree);
        }
    }else if (factor < -1) {
        if (getBalanceFactor(tree->leftChild) > 0){
            // RL
            re = rightLeftRotation(tree);
        }else{
            // RR
            re = rightRightRotation(tree);
        }
    }else
        return tree;
    if (!avlBalanced(re))
        return balance(re);
    return re;
};

template<typename T>
avlTree<T> *create(vector<T> tree){
    avlTree<T> *re;
    avlTree<T> *t = re;
    for (int i=0; i<tree.size(); i++){
        t = new avlNode<T>(tree[i]);
        t = t->rightChild;
    }
    re = balance(re);
    return re;
}

template<typename T>
void del(avlTree<T> *tree, T element){

};


template<typename T>
avlTree<T> *insert(avlTree<T> *tree, T element){

};

template<typename T>
avlTree<T> *update(avlTree<T> *tree, T element){

};

template<typename T>
avlTree<T> *search(avlTree<T> *tree, T element){
    avlTree<T> *t = tree;
    if ((t->element > element)){
        t = t->leftChild;
    }else if ((t->element == element)){
        return t;
    }else{
        t = t->rightChild;
    }

    return nullptr;
};

#endif
