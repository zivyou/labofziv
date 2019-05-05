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
    void preorder(vector<int> &re, TreeNode* root){
        if (!root)
            return;
        re.push_back(root->val);
        if (root->left)
            preorder(re, root->left);
        if (root->right)
            preorder(re, root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        preorder(re, root);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
