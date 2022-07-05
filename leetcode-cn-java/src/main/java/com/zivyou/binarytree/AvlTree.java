package com.zivyou.binarytree;

class AvlTreeNode<T extends Comparable> {
    T data;
    AvlTreeNode<T> left;
    AvlTreeNode<T> right;
    AvlTreeNode<T> parent;
    int height;

    public void setData(T data) {
        this.data = data;
    }

    public void setLeft(AvlTreeNode<T> left) {
        this.left = left;
    }

    public void setRight(AvlTreeNode<T> right) {
        this.right = right;
    }

    public void setParent(AvlTreeNode<T> parent) {
        this.parent = parent;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public AvlTreeNode() {
    }

    public AvlTreeNode(T data) {
        this.data = data;
        this.left = this.right = this.parent = null;
        int height = 1;
    }
}

public class AvlTree<T> {
}
