#include <cstdio>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void traversal(TreeNode* root, int& pre, int& result) {
        if (root->left == nullptr && root->right == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            traversal(root->left, pre, result);
        }
        auto t = std::abs(root->val-pre);
        if (t < result) {
            result = t;
        }
        pre = root->val;
        if (root->right != nullptr) {
            traversal(root->right, pre, result);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> data;
        int min = INT_MAX; int pre = min;
        traversal(root, pre, min);
        return min;
    }
};

int main(int argc, char* argv[]) {
    Solution s;
}
