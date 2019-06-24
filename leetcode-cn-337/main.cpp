#include <iostream>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<TreeNode*, int> m;
    int rawRob1(TreeNode* root){
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;

        return root->val + rawRob2(root->left) + rawRob2(root->right);
    }

    int rawRob2(TreeNode* root){
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 0;

        return rob(root->left) + rob(root->right);
    }
    int rob(TreeNode* root) {
        if (!root)
            return 0;

        if (m.find(root) != m.end())
            return m[root];

        int v1 = root->val + rawRob2(root->left) + rawRob2(root->right);
        int v2 = rob(root->left) + rob(root->right);
        m[root] = max(v1, v2);
        return max(v1, v2);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
