#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> re;
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)
            return re;
        if (root->left)
            inorderTraversal(root->left);
        re.push_back(root->val);
        if (root->right)
            inorderTraversal(root->right);
        return re;
    }
};

int main(){
    return 0;
}