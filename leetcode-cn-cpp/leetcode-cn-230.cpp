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
    int midOrder(TreeNode* root, int k, int& count, int& re){
        if (!root)
            return 0;
        if (count >= k){
            return re;
        }
        if (root->left){
            midOrder(root->left, k, count, re);
        }
        // print root->val
        count++;
        if (count == k){
            re = root->val;
            return root->val;
        }
        if (root->right){
            midOrder(root->right, k, count, re);
        }

        if (k == count){
            return re;
        }

        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int re = 0;
        int count = 0;
        midOrder(root, k, count, re);
        return re;
    }
};

int main(){
    return 0;
}