#include <vector>
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
    void rawBuildTree(TreeNode* root, vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2){
        if (l1 > r1) return ;
        if (l2 > r2) return ;
        if (!root) return;
        int i=0;
        for (i=l2; i<=r2; i++){
            if (root->val == inorder[i])
                break;
        }
        cout<<"current:"<<inorder[i]<<endl;

        TreeNode* leftChild;
        if (i != l2)
            leftChild = new TreeNode(preorder[l1+1]);
        else
            leftChild = NULL;
        TreeNode* rightChild;
        if (i != r2)
            rightChild = new TreeNode(preorder[l1+i-l2+1]);
        else
            rightChild = NULL;

        root->left = leftChild;
        root->right = rightChild;
        rawBuildTree(leftChild, preorder, l1+1, l1+i-l2, inorder, l2, i-1);
        rawBuildTree(rightChild, preorder, l1+i-l2+1, r1, inorder, i+1, r2);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() <= 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        rawBuildTree(root, preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }

    void print(TreeNode * root){
        if (!root) return;
        if (root->left)
            print(root->left);
        cout<<root->val<<" ";
        if (root->right)
            print(root->right);
    }
};

int main(){
    vector<int> preorder({3,9,20,15,7});
    vector<int> inorder({9,3,15,20,7});

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    s.print(root);
    return 0;
}
