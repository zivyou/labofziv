#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
private:
    Node * pre = NULL;
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    int depth(Node *root){
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    void rawConnect(Node *root, int level){

        if (level < 1)
            return;
        if (level == 1){
            if (root->left)
                root->left->next = root->right;
            //cout<<root->val<<" ";
            if (pre){
                pre->next = root;
            }
            pre = root;
        }
        if (root->left)
            rawConnect(root->left, level-1);
        if (root->right)
            rawConnect(root->right, level-1);
    }

    Node* connect(Node* root) {
        if (!root) return NULL;
        int d = depth(root);
        for (int i=1; i<=d; i++)
            rawConnect(root, i);
        Node *n = root;
        while (n){
            n->next = NULL;
            n = n->right;
        }
        return root;
    }
};

int main()
{
    Node *root = new Node(1, NULL, NULL, NULL);
    root->left = new Node(2, NULL, NULL, NULL);
    root->right = new Node(3, NULL, NULL, NULL);
    root->left->left = new Node(4, NULL, NULL, NULL);
    root->left->right = new Node(5, NULL, NULL, NULL);
    root->right->left = new Node(6, NULL, NULL, NULL);
    root->right->right = new Node(7, NULL, NULL, NULL);
    Solution s;
    s.connect(new Node(0, NULL, NULL, NULL));
    return 0;
}
