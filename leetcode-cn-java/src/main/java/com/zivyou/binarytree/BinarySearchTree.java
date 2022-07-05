package com.zivyou.binarytree;

public class BinarySearchTree<T extends Comparable<T>> extends BinaryTree<T>{

    boolean isCompleteBinaryTree() {
        return true;
    }

    boolean isBalanced() {
        return true;
    }


    public BinarySearchTree(BinaryTree<T> tree) {
        super();
        if (BinarySearchTree.isBinarySearchTree(tree)) {
            this.root = tree.root;
        }
    }

    static public boolean isBinarySearchTree(BinaryTree<?> tree) {
        assert null != tree;
        return true;
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

    public Node<T> remove2(Node<T> node) {
        if (null == node) return null;
        if (root == null) return null;

        Node<T> y = null; // 最终需要删除并返回的节点;
        Node<T> x = null; // 被删除的节点下面的子树的根;

        if (node.left == null && node.right == null) {
            y = node;
        } else if (node.left != null && node.right == null) {
            y = node;
            x = node.left;
        } else if (node.left == null && node.right != null) {
            y = node;
            x = node.right;
        } else {
            Node<T> s = successor(node);
            y = node;
        }

        if (y == root) {
            this.root = null;
        }
        return y;
    }

    public Node<T> remove(Node<T> node) {
        if (null == node) return null;
        if (root == null) return null;
        if (node.left == null && node.right == null) {
            if (root == node) {
                root = null;
                return node;
            } else {
                if (node == node.parent.left) {
                    node.parent.left = null;
                    return node;
                } else {
                    node.parent.right = null;
                    return node;
                }
            }
        } else if (node.left != null && node.right == null) {
            if (root == node) {
                root = node.left;
                return node;
            } else {
                if (node == node.parent.left) {
                    node.parent.left = node.left;
                    return node;
                } else {
                    node.parent.right = node.left;
                    return node;
                }
            }
        } else if (node.left == null && node.right != null) {
            if (root == node) {
                root = node.right;
                return node;
            } else {
                if (node == node.parent.left) {
                    node.parent.left = node.right;
                    return node;
                } else {
                    node.parent.right = node.right;
                    return node;
                }
            }
        } else {
            Node<T> successor = successor(node);
            remove(successor);
            successor.left = node.left;
            successor.right = node.right;
            if (root == node) {
                root = successor;
                return node;
            } else {
                if (node == node.parent.left) {
                    node.parent.left = successor;
                    return node;
                } else {
                    node.parent.right = successor;
                    return node;
                }
            }
        }
    }

    public Node<T> search(T data) {
        Node<T> current = root;
        int result;
        while (current != null && (result = current.data.compareTo(data)) != 0) {
            if (result < 0) {
                current = current.right;
            } else if (result > 0) {
                current = current.left;
            } else {
                return current;
            }
        }
        return current;
    }

    public boolean remove(T data) {
        Node<T> node = remove(search(data));
        return null != node;
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
