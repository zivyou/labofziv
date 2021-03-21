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

    void rawCountNode(TreeNode* root, int &re){
        if (root)
            re++;
        else
            return;
        rawCountNode(root->left, re);
        rawCountNode(root->right, re);
    }

    int countNodes(TreeNode* root) {
        int re = 0;
        rawCountNode(root, re);
        return re;
    }
};

int main(){

    return 0;
}