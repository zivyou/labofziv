package com.zivyou.binarytree;

import lombok.Getter;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

@Getter
class Node<T> {
    Node<T> left;
    Node<T> right;
    Node<T> parent;
    T data;

    public Node(T data) {
        this.data = data;
        left = null;
        right = null;
        parent = null;
    }

    public Node(Node<T> left, Node<T> right, T data) {
        this.left = left;
        this.right = right;
        this.data = data;
        this.parent = null;
    }

    public Node<T> addLeftChild(Node<T> node) {
        this.left = node;
        node.parent = this;
        return node;
    }

    public Node<T> addRightChild(Node<T> node) {
        this.right = node;
        node.parent = this;
        return node;
    }

    public Node() {
        parent = left = right = null;
    }
}

public class BinaryTree<T> {
    private final Node<T> root;
    public BinaryTree() { this.root=null; }
    public BinaryTree(Node<T> root) {
        this.root = root;
    }

    private void rawPreOrder(Node<T> node, List<T> tmpResult) {
        if (null == node) return;
        tmpResult.add(node.getData());
        rawPreOrder(node.left, tmpResult);
        rawPreOrder(node.right, tmpResult);
    }

    List<T> preOrder() {
        List<T> result = new ArrayList<>();
        rawPreOrder(root, result);
        return result;
    };

    private void rawMidOrder(Node<T> node, List<T> tmpResult) {
        if (null == node) return;
        rawPreOrder(node.left, tmpResult);
        tmpResult.add(node.getData());
        rawPreOrder(node.right, tmpResult);
    }
    List<T> midOrder() {
        List<T> result = new ArrayList<>();
        rawMidOrder(root, result);
        return result;
    };

    private void rawPostOrder(Node<T> node, List<T> tmpResult) {
        if (null == node) return;
        rawPreOrder(node.left, tmpResult);
        rawPreOrder(node.right, tmpResult);
        tmpResult.add(node.getData());
    }

    List<T> postOrder() {
        List<T> result = new ArrayList<>();
        rawPostOrder(root, result);
        return result;
    };

    List<T> preOrder2() {
        // 非递归实现先序遍历
        Stack<Node<T>> stack = new Stack<>();
        List<T> result = new ArrayList<>();
        Node<T> current = this.root;
        while (null != current || stack.empty() == false) {
            if (null != current) {
                result.add(current.getData());
                stack.push(current); // 记住来的路
                current = current.left;
            } else {
                Node<T> newNode = stack.pop();
                current = newNode.right;
            }
        }
        return result;
    };

    List<T> midOrder2() {
        // 非递归实现中序遍历
        Stack<Node<T>> stack = new Stack<>();
        List<T> result = new ArrayList<>();
        Node<T> node = this.root;
        while (null != node || stack.empty() == false) {
            if (null != node) {
                stack.push(node);
                node = node.left;
            } else {
                node = stack.pop();
                result.add(node.data);
                node = node.right;
            }
        }
        return result;
    };

    List<T> postOrder2() {
        // 非递归实现后序遍历
        Stack<Node<T>> stack = new Stack<>();
        List<T> result = new ArrayList<>();
        Node<T> node = this.root;
        while (null != node || stack.empty() == false) {
            if (null != node) {
                stack.push(node);
                result.add(node.data);
                node = node.right;
            } else {
                node = stack.pop();
                node = node.left;
            }
        }

        Collections.reverse(result);
        return result;
    };

    public List<T> serialize() {
        return null;
    }

    static public BinaryTree<?> deserialize(List<?> data) {
        return null;
    }

    static public Node<?> lowestCommonAncestor(BinaryTree<?> treeA, BinaryTree<?> treeB) {
        return null;
    }

    private Node<T> mostRight(Node<T> node) {
        while (node.right != null) {
            node = node.right;
        }
        return node;
    }

    private Node<T> mostLeft(Node<T> node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    // 中序遍历中二叉树的前驱节点
    public Node<T> predecessor(Node<T> node) {
        if (null == node) return null;
        if (null != node.left) {
            return mostRight(node.left);
        } else {
            Node<T> p = node.parent;
            while (node == p.left) {
                node = p;
                p = node.parent;
            }
            return p;
        }
    }

    // 中序遍历中二叉树的后继节点
    public Node<T> successor(Node<T> node) {
        if (null == node) return null;
        if (null != node.right) {
            return mostLeft(node.right);
        } else {
            Node<T> p = node.parent;
            while (node == p.right) {
                node = p;
                p = node.parent;
            }
            return p;
        }
    }
}
