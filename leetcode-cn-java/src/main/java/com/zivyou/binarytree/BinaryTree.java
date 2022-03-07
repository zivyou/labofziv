package com.zivyou.binarytree;

import lombok.Getter;

import java.lang.reflect.Type;
import java.util.*;

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
    protected Node<T> root;
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

    private void rawSerialize(Node<T> node, StringBuffer sb) {
        if (null == node) {
            sb.append("#").append(",");
            return;
        }
        sb.append(node.data.toString()).append(",");
        rawSerialize(node.left, sb);
        rawSerialize(node.right, sb);
    }

    public String serialize() {
        StringBuffer sb = new StringBuffer();
        rawSerialize(this.root, sb);
        return sb.toString();
    }

    static  private <T extends Comparable<T>> Node<T> deserialize(LinkedList<String> words, Node<T> parent, TypeCast<T> caster) {
        if (words == null || words.size() <= 0) return null;
        String head = words.removeFirst();
        if (null == head) return null;
        if (head.equals("#")) return null;
        Node<T> node = new Node<T>(caster.parseFromString(head));
        node.parent = parent;
        node.left = deserialize(words, node, caster);
        node.right = deserialize(words, node, caster);
        return node;
    }

    static public <T extends Comparable<T>> BinaryTree<T> deserialize(String data, TypeCast<T> caster) {
        LinkedList<String> words = new LinkedList<>();
        for (String s: data.split(",")) {
            words.addLast(s);
        }
        Node<T> root = BinaryTree.deserialize(words, null, caster);
        return new BinaryTree<T>(root);
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
            while (null != p && node == p.left) {
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
            if (null == p) return null;
            while (null != p && node == p.right) {
                node = p;
                p = node.parent;
            }
            return p;
        }
    }
}
