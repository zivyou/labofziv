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
    TreeNode * minNode(TreeNode* root){
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root;
        if (!root->left)
            return root;
        
        return minNode(root->left);
    }
    TreeNode* father(TreeNode* root, TreeNode* p){
        if (!root)
            return nullptr;
        if (root->left == p || root->right == p)
            return root;
        
        TreeNode* re = father(root->left, p);
        if (re)
            return re;
        re = father(root->right, p);
        if (re)
            return re;
        return nullptr;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right)
            return minNode(p->right);
        else
        {
            TreeNode* f = father(root, p);
            while (f && p == f->right){
                p = f;
                f = father(root, f);
            }

            return f;
        }
    }
};

int main(){
    return 0;
}