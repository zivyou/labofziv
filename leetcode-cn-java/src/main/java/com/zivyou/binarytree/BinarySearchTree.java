package com.zivyou.binarytree;

import java.util.List;

public class BinarySearchTree<T extends Comparable<T>> extends BinaryTree<T>{

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

    public BinarySearchTree<T> build(T[] data) {
        return null;
    }

    public boolean add(Node<T> node) {
        if (this.root == null) {
            this.root = node;
        } else {
            Node<T> current = root;
            while (current != null) {
                if (node.data.compareTo(current.data) < 0) {
                    if (current.left == null) {
                        current.left = node;
                        node.parent = current;
                        return true;
                    } else {
                        current = current.left;
                    }
                } else if (node.data.compareTo(current.data) > 0) {
                    if (current.right == null) {
                        current.right = node;
                        node.parent = current;
                        return true;
                    } else {
                        current = current.right;
                    }
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    public boolean add(T data) {
        return add(new Node<>(data));
    }

    public boolean remove(Node<T> node) {
        if (null == node) return false;

        return true;
    }

    public boolean remove(T data) {
        return true;
    }

    public boolean exist(Node<T> node) {
        if (null == node) return false;
        Node<T> current = this.root;
        while (current != null) {
            int result = current.data.compareTo(node.data);
            if (result < 0) {
                current = current.right;
            } else if (result > 0) {
                current = current.left;
            } else
                return true;
        }
        return false;
    }

    public boolean exist(T data) {
        Node<T> current = this.root;
        while (current != null) {
            int result = current.data.compareTo(data);
            if (result < 0) {
                current = current.right;
            } else if (result > 0) {
                current = current.left;
            } else
                return true;
        }
        return false;
    }
}
