package com.zivyou.binarytree;

import org.junit.Test;

import java.util.List;

public class BinaryTreeTests {
    @Test
    public void test01() {
        Node<Integer> node = new Node<>(1);
        node.left = new Node<>(2);
        node.right = new Node<>(3);
        node.left.left = new Node<>(4);
        node.left.right = new Node<>(5);
        node.right.right = new Node<>(6);
        BinaryTree<Integer> tree = new BinaryTree<>(node);

        List<Integer> result = tree.preOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.midOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.postOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();
    }

    @Test
    public void test02() {
        Node<Integer> node = new Node<>(1);
        node.left = new Node<>(2);
        node.left.left = new Node<>(3);
        node.left.left.left = new Node<>(4);
        node.left.left.left.left = new Node<>(5);
        node.left.left.left.left.left = new Node<>(6);
        BinaryTree<Integer> tree = new BinaryTree<>(node);

        List<Integer> result = tree.preOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.midOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();
    }

    @Test
    public void test03() {
        Node<Integer> node = new Node<>(1);
        node.right = new Node<>(2);
        node.right.right = new Node<>(3);
        node.right.right.right = new Node<>(4);
        node.right.right.right.right = new Node<>(5);
        node.right.right.right.right.right = new Node<>(6);
        BinaryTree<Integer> tree = new BinaryTree<>(node);

        List<Integer> result = tree.preOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.midOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.postOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();
    }

    @Test
    public void test04() {
        Node<Integer> node = new Node<>(1);
        node.right = new Node<>(2);
        node.right.left = new Node<>(3);
        node.right.left.right = new Node<>(4);
        node.right.left.right.left = new Node<>(5);
        node.right.left.right.left.right = new Node<>(6);
        BinaryTree<Integer> tree = new BinaryTree<>(node);

        List<Integer> result = tree.preOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.midOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();

        result = tree.postOrder2();
        for (Integer d: result) {
            System.out.println(d+", ");
        }
        System.out.println();
    }

    @Test
    public void test05() {
        Node<Integer> node = new Node<>(1);
        node.addLeftChild(new Node<>(2)).addLeftChild(new Node<>(3))
                .addRightChild(new Node<>(4))
                .addRightChild(new Node<>(5))
                .addRightChild(new Node<>(6));
        BinaryTree<Integer> tree = new BinaryTree<>(node);
        Node<Integer> current = node;
        while (current != null) {
            Node<Integer> pre = tree.predecessor(current);
            if (null != pre)
                System.out.println(pre.data+", ");
            current = pre;
        }
    }
}
