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

    public Node<T> remove(Node<T> node) {
        if (null == node) return null;
        if (root == null) return null;
        Node<T> successor = this.successor(node);
        if (null != node.parent) {
            if (null == node.left && null == node.right) {
                this.root = null;
            } else if (null == node.left && null != node.right) {
                this.root = node.right;
                this.root.parent = null;
            } else if (null != node.left && null == node.right) {
                this.root = node.left;
                this.root.parent = null;
            } else {
                Node<T> tmpNode = remove(successor);
                tmpNode.parent = node.parent;
                tmpNode.left = node.left;
                tmpNode.right = node.right;
                if (node == node.parent.left) {
                    node.parent.left = tmpNode;
                } else {
                    node.parent.right = tmpNode;
                }
            }
            node.left = node.right = null;
            return node;
        } else {
            if (null == node.left && null == node.right) {
                if (node == node.parent.left) {
                    node.parent.left = null;
                } else {
                    node.parent.right = null;
                }
            } else if (null == node.left && null != node.right) {
                if (node == node.parent.left) {
                    node.parent.left = node.right;
                } else {
                    node.parent.right = node.right;
                }
            } else if (null != node.left && null == node.right) {
                if (node == node.parent.left) {
                    node.parent.left = node.left;
                } else {
                    node.parent.right = node.left;
                }
            } else {
                Node<T> tmpNode = remove(successor);
                tmpNode.parent = node.parent;
                tmpNode.left = node.left;
                tmpNode.right = node.right;
                if (node == node.parent.left) {
                    node.parent.left = tmpNode;
                } else {
                    node.parent.right = tmpNode;
                }
            }
            node.left = node.right = null;
            return node;
        }
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
