#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode * root){
    if (!root) return;
    if (root->left)
        print(root->left);
    cout<<root->val<<" ";
    if (root->right)
        print(root->right);
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    print(root);
    return 0;
}
