package com.zivyou.binarytree;

import java.util.List;

public class BinarySearchTree<T> extends BinaryTree<T>{

    boolean isBinarySearchTree() {
        return true;
    }

    boolean isCompleteBinaryTree() {
        return true;
    }

    boolean isBalanced() {
        return true;
    }

    static public boolean isBinarySearchTree(BinaryTree<?> tree) {
        assert null != tree;
        return false;
    }

    static public boolean isCompleteBinaryTree(BinaryTree<?> tree) {
        assert null != tree;
        return false;
    }

    static public boolean isBalanced(BinaryTree<?> tree) {
        assert null != tree;
        return false;
    }

    public boolean rebalance() {
        return false;
    }

}
