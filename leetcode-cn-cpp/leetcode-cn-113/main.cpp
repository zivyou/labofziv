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
    void rawPathSum(vector<vector<int>>&re, vector<int> curPath, TreeNode *root, int sum){

        if (!root){
            //curPath.pop_back();
            return;
        }

        if (!root->left && !root->right){
            if (sum == root->val){
                curPath.push_back(root->val);
                re.push_back(curPath);
                return;
            }else{
                if (curPath.size())
                    curPath.pop_back();
                return;
            }

        }


        curPath.push_back(root->val);
        if (root->left)
            rawPathSum(re, curPath, root->left, sum-root->val);
        if (root->right)
            rawPathSum(re, curPath, root->right, sum-root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> re;
        if (!root)
            return re;
        vector<int> curPath;
        rawPathSum(re, curPath, root, sum);
        return re;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
