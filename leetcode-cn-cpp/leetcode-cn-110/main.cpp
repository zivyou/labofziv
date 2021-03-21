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
    int max(int a, int b){
        if (a > b)
            return a;
        else
            return b;
    }
    int height(TreeNode *root){
        if (!root) return 0;
        return max(height(root->left), height(root->right))+1;
    }
    int abs(int a, int b){
        if (a > b)
            return a-b;
        else
            return b-a;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int lheight = height(root->left);
        int rheight = height(root->right);

        if (abs(lheight, rheight) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;

    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
