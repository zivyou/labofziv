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
    void rawBuildTree(TreeNode* root, vector<int>& postorder, int l1, int r1, vector<int>& inorder, int l2, int r2){
        if (l1 > r1) return ;
        if (l2 > r2) return ;
        if (!root) return;
        int i=0;
        for (i=l2; i<=r2; i++){
            if (root->val == inorder[i])
                break;
        }

        TreeNode* leftChild;
        if (i != l2)
            leftChild = new TreeNode(postorder[r1-(r2-i+1)]);
        else
            leftChild = NULL;
        TreeNode* rightChild;
        if (i != r2)
            rightChild = new TreeNode(postorder[r1-1]);
        else
            rightChild = NULL;

        root->left = leftChild;
        root->right = rightChild;
        rawBuildTree(leftChild, postorder, l1, r1-(r2-i+1), inorder, l2, i-1);
        rawBuildTree(rightChild, postorder, r1-(r2-i), r1-1, inorder, i+1, r2);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() <= 0)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        rawBuildTree(root, postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
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
    vector<int> inorder({9,3,15,20,7});
    vector<int> postorder({9,15,7,20,3});

    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);
    s.print(root);
    return 0;
}
