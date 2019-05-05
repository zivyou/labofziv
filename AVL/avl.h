#ifndef __AVL_H__
#define __AVL_H__

#include <vector>

using namespace std;

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

#define avlTree avlNode

template<typename T>
avlTree<T> *balance(avlTree<T> *tree){

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