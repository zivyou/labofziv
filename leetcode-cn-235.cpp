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
    TreeNode* preOrder(TreeNode* root, TreeNode* p, TreeNode* q){
        int a = p->val > q->val ? q->val : p->val;
        int b = p->val > q->val ? p->val : q->val;
        if (root){
            if (a <= root->val && root->val <= b)
                return root;
            else if (a < root->val && b < root->val){
                return preOrder(root->left, p, q);
            }else if (a > root->val && b > root->val){
                return preOrder(root->right, p, q);
            }else
                return nullptr;
        }

        return nullptr;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return preOrder(root, p, q);
    }
};

int main(){
    return 0;
}