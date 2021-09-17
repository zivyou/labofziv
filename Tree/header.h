
struct Node {
  int val;
  struct Node* left;
  struct Node* right;
  Node(int v) { this->val = v; this->left = nullptr; this->right=nullptr; }
};

typedef struct Node* Tree;
