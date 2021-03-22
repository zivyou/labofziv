#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return  vector<vector<int>>();
        vector<vector<int>> re;
        vector<int> v;
        queue<TreeNode *> q;
        q.push(root);
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        while (!q.empty()){
            TreeNode *n;
            n = q.front();
            q.pop();

            currentLevelCount--;
            if (n){
                v.push_back(n->val);
                q.push(n->left);
                q.push(n->right);
                nextLevelCount += 2;
            }
            if (currentLevelCount == 0){
                re.push_back(v);
                v.clear();
                currentLevelCount = nextLevelCount;
                nextLevelCount=0;
            }
        }
        return re;
    }
};

int main()
{
        TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(5);

    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(6);

    Solution s;
    vector<vector<int>>  re = s.levelOrder(root);

    for (int i=0; i<re.size(); i++){
        for (int j=0; j<re[i].size(); j++)
            cout<<re[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
