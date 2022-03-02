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

    @Override
    public List<T> preOrder() {
        return null;
    }

    @Override
    public List<T> midOrder() {
        return null;
    }

    @Override
    public List<T> postOrder() {
        return null;
    }

    @Override
    public List<T> preOrder2() {
        return null;
    }

    @Override
    public List<T> midOrder2() {
        return null;
    }

    @Override
    public List<T> postOrder2() {
        return null;
    }

    public Node<T> processor(Node<T> node) {
        return null;
    }

    public Node<T> successor(Node<T> node) {
        return null;
    }

    public boolean rebalance() {
        return false;
    }

    @Override
    public List<T> serialize() {
        return null;
    }
}
