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
    struct preNode {
        Node *n;
        int level;
    };
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    int depth(Node *root){
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    void rawConnect(Node *root, int level, int originLevel, preNode &pre){
        if (!root) return;
        if (level < 1)
            return;
        if (level == 1){
            if (root->left)
                root->left->next = root->right;
            if (pre.level+1 == originLevel)
                pre.n->next = NULL;
            else{
                pre.n->next = root;
            }
            pre.level = originLevel;
            pre.n = root;
            return;
        }
        if (root->left)
            rawConnect(root->left, level-1, originLevel, pre);
        if (root->right)
            rawConnect(root->right, level-1, originLevel, pre);
    }

    Node* connect(Node* root) {
        if (!root) return NULL;
        int d = depth(root);
        preNode pre;
        pre.n = root;
        root->next = NULL;
        pre.level = 0;
        for (int i=1; i<=d; i++)
            rawConnect(root, i, i, pre);
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
    //root->right->left = new Node(6, NULL, NULL, NULL);
    root->right->right = new Node(7, NULL, NULL, NULL);
    Solution s;
    s.connect(root);
    return 0;
}
