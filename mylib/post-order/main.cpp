#include <iostream>
#include <stack>

using namespace std;

struct Node {
  struct Node* left;
  struct Node* right;
  int val;
  Node(int x) {
    this->val = x;
    this->left = NULL;
    this->right = NULL;
  }
};

void postOrder(Node* tree) {
  stack<Node*> st;
  Node* c = tree; Node* h = tree;
  st.push(tree);
  while (!st.empty()) {
    c = st.top();
    if (c->left != NULL && c->left != h && c->right != h) {
      st.push(c->left);
    } else if (c->right != NULL && c->right != h) {
      st.push(c->right);
    } else {
      h = c;
      std::cout<<st.top()->val<<" ";
      st.pop();
    }
  };
}

int main() {
  Node* tree = new Node(1);
  tree->left = new Node(2);
  tree->right = new Node(3);
  tree->left->left = new Node(4);
  tree->left->right = new Node(5);
  tree->right->left = new Node(6);
  tree->right->right = new Node(7);
  tree->left->right->left = new Node(8);
  tree->right->left->left = new Node(9);

  postOrder(tree);
}