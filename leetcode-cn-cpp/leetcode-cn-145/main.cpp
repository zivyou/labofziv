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
    void postorder(vector<int> &v, TreeNode* root){
        if (!root)
            return;
        if (root->left){
            postorder(v, root->left);
        }

        if (root->right){
            postorder(v, root->right);
        }

        v.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> re;
        postorder(re, root);
        return re;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
