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
    int rawLongestConsecutive(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        
        int r1 = 1; int r2 = 1;
        if (root->left)
            if (root->val+1 == root->left->val)
                r1 = 1+rawLongestConsecutive(root->left);
        if (root->right)
            if (root->val+1 == root->right->val)
                r2 = 1+rawLongestConsecutive(root->right);
        
        return max(r1, r2);
    }

    int longestConsecutive(TreeNode* root){
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 1;
        int re = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            TreeNode * t = q.front();
            q.pop();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            int tmp = rawLongestConsecutive(t);
            if (tmp > re)
                re = tmp;
        }
        
        return re;
    }
};

int main(){
    TreeNode * root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(1);
    Solution s;
    cout<<s.longestConsecutive(root)<<endl;
    return 0;
}