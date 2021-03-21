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
    double abs(double a, double b){
        if (a > b)
            return a - b;
        else 
            return b-a;
    }

    int closestValue(TreeNode* root, double target) {
        if (!root){
            return INT_MAX;
        }
        if (!root->left && !root->right){
            return root->val;
        }

        if (root->val > target){
            if (root->left){
                int t = closestValue(root->left, target);
                return abs(root->val, target) > abs(t, target) ? t : root->val;
            }else{
                return root->val;
            }
        }else{
            if (root->right){
                int t = closestValue(root->right, target);
                return abs(root->val, target) > abs(t, target) ? t : root->val;
            }else{
                return root->val;
            }
        }
    }
};

int main(){

    return 0;
}