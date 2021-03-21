#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int nextLevelAmount = 0;
        int curLevelAmount = 1;
        queue<TreeNode *> q;
        vector<int> re;
        if (!root)
            return re;
        q.push(root);
        while (!q.empty()){
            TreeNode * t = q.front();
            q.pop();
            curLevelAmount--;

            if (t->left){
                q.push(t->left);
                nextLevelAmount++;
            }

            if (t->right){
                q.push(t->right);
                nextLevelAmount++;
            }

            if (curLevelAmount == 0){
                re.push_back(t->val);
                curLevelAmount = nextLevelAmount;
                nextLevelAmount = 0;
            }
        }

        return re;
    }
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);
    Solution s;
    vector<int> re;
    re = s.rightSideView(root);
    for (int i=0; i<re.size(); i++)
        cout<<re[i]<<" ";
    cout<<endl;

    return 0;
}
