#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void rawBuildTree(TreeNode *&root, vector<int>& nums, int l, int r){
        //if (!root) return;
        if (l > r) return;

        int mid = (l+r)/2;
        root = new TreeNode(nums[mid]);
        rawBuildTree(root->left, nums, l, mid-1);
        rawBuildTree(root->right, nums, mid+1, r);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() <= 0) return NULL;
        TreeNode* root;
        rawBuildTree(root, nums, 0, nums.size()-1);
        return root;
    }
    void print(TreeNode *root){
        if (!root) return;
        if (root->left)
            print(root->left);
        cout<<root->val<<" ";
        if (root->right)
            print(root->right);
    }
};
int main()
{
    vector<int> v({-10,-3,0,5,9});
    Solution s;
    TreeNode *root = s.sortedArrayToBST(v);
    s.print(root);
    cout << "Hello world!" << endl;
    return 0;
}
