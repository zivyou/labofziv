#pragma once

#include <string>
#include <iostream>
#include <queue>
#include <fstream>

template<typename T>
class Node {
public:
  T element;
  Node *leftChild;
  Node *rightChild;

public:
  Node(T v) {
    this->element = v;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
  }


  void display() {
    std::string result = "";
    graphviz();
    // dot  -Tpng output.dot -o output.png
  }

public:

  void graphviz() {
    std::string data = "digraph g{\n";
    /**
     * 下面是一个先序遍历（dfs）。中左右
     */
    std::queue<Node<T> *> q;
    q.push(this);
    while (!q.empty()) {
      Node<T> *n = q.front();
      q.pop();
      data += std::to_string(n->element) + ";\n";
      if (!n->leftChild && !n->rightChild) continue;
      if (n->leftChild) {
        data += std::to_string(n->element) + "->" + std::to_string(n->leftChild->element) + " [label=left];\n";
        q.push(n->leftChild);
      } else {
        data += "NULL" + std::to_string(long(n + 1)) + "[style=invis];\n";
        data += std::to_string(n->element) + "->NULL" + std::to_string(long(n + 1)) + "[style=invis];\n";
      }

      if (n->rightChild) {
        data += std::to_string(n->element) + "->" + std::to_string(n->rightChild->element) + " [label=right];\n";
        q.push(n->rightChild);
      } else {
        data += "NULL" + std::to_string(long(n + 2)) + "[style=invis];\n";
        data += std::to_string(n->element) + "->NULL" + std::to_string(long(n + 2)) + "[style=invis];\n";
      }
    }
    data += "}";
    std::cout<<data<<std::endl;
    std::fstream fs("output.dot", std::ios::out);
    if (!fs.is_open()) {
      fs.clear();
      fs.open("output.dot",  std::ios::out);
    }
    if (fs.is_open()) {
      fs << data;
      fs.close();
    } else {
      std::cout<<"file /tmp/output.dot open failed!"<<std::endl;
    }
  }
};

/*
int main() {
  typedef Node<int> TreeNode;
  TreeNode *root = new TreeNode(1);
  root->leftChild = new TreeNode(2);
  root->rightChild = new TreeNode(3);
  root->leftChild->rightChild = new TreeNode(4);
  root->leftChild->rightChild->leftChild = new TreeNode(5);
  root->display();

}
*/

