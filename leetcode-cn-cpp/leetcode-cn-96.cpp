#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1)
            return 1;
        int* dp = new int[n+1];
        dp[1] = 1;
        dp[0] = 1;
        for (int i=0; i<n; i++){
            int sum = 0;
            for (int j=1; j<=i+1; j++){
                sum += dp[j-1]*dp[i-j+1];
            }
            dp[i+1] = sum;
        }
        return dp[n];
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution2 {
public:
    int origin = 1;
    int preNum = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)){
            return false;
        }
        if (origin ){
            origin = 0;
        }else{
            if (root->val <= preNum){
                return false;
            }
        }
        preNum = root->val;
        if (!isValidBST(root->right))
            return false;

        return true;
    }
};

int main(){
    Solution s;
    cout<<s.numTrees(3)<<endl;
    return 0;
}