#include <iostream>
#include <map>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;


class Solution {
public:
    map<TreeNode*, bool> m;
    int rawCountUnivalSubtrees(TreeNode* root){
        int count = 0;
        for (auto pair : m){
            if (pair.second)
                count++;
        }
        return count;
    }

    bool isUnival(TreeNode* root){
        if (m.find(root) != m.end())
            return m[root];
        if (!root->left && !root->right){
            m[root] = true;
            return m[root];
        }

        if (!root->left && root->right){
            bool left = isUnival(root->right);
            m[root] = (root->val == root->right->val) && left;
            return m[root];
        }

        if (root->left && !root->right){
            bool right = isUnival(root->left);
            m[root] = (root->val == root->left->val) && right;
            return m[root];
        }

        if (root->left && root->right){
            bool left = isUnival(root->right);  bool right = isUnival(root->left);
            m[root] = (root->val == root->left->val) && (root->val == root->right->val) &&
                left && right;
            return m[root];
        }

        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (!root)
            return 0;
        isUnival(root);
        return rawCountUnivalSubtrees(root);
    }
};

int main(){
    return 0;
}