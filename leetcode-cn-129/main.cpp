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
    void cal(int &re, int tmpRe, TreeNode* root){
        if (!root)
            return;
        if (!root->right && !root->left){
            re = re + tmpRe * 10 + root->val;
            return ;
        }
        if (root->right){
            cal(re, tmpRe*10+root->val, root->right);

        }
        if (root->left){
            cal(re, tmpRe*10+root->val, root->left);

        }
    }
    int sumNumbers(TreeNode* root) {
        int re = 0;
        int tmpRe = 0;
        cal(re, tmpRe, root);
        return re;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
