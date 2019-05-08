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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode *left = root->left;
        TreeNode *right = root->right;

        root->left = right;
        root->right = left;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main(){
    return 0;
}