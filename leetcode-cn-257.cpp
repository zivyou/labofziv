#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void search(TreeNode* root, vector<string>& re, string path){
        if (!root)
            return;
        if (!root->left && !root->right){
            re.push_back(path);
            return;
        }

        if (root->left){
            search(root->left, re, path + "->" + std::to_string(root->left->val));
        }

        if (root->right){
            search(root->right, re, path + "->" + std::to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> re;
        if (!root)
            return re;
        search(root, re, std::to_string(root->val));
        return re;
    }
};

int main(){
    return 0;
}