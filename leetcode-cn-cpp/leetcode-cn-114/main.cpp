#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right)
            return;
        if (root->left && !root->right){
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
            return;
        }

        if (!root->left && root->right){
            flatten(root->right);
            return;
        }

        if (root->left && root->right){
            TreeNode * n = root->right;
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
            TreeNode *t = root;
            while (t->right)
                t = t->right;
            t->right = n;
            flatten(n);
        }

    }
};

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    Solution s;
    s.flatten(root);

    TreeNode *r = root;
    cout<<" ======================================= "<<endl;
    while (r){
        cout<<r->val<<" ";
        r = r->right;
    }
    return 0;
}
