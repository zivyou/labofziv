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
    int origin = 1;
    int preNum = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)){
            return false;
        }
        if (origin ){
            origin = 0;
        }else{
            if (root->val <= preNum){
                return false;
            }
        }
        preNum = root->val;
        if (!isValidBST(root->right))
            return false;

        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isValidBST(NULL) << endl;
    return 0;
}
