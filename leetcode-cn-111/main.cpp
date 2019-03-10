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
    int min(int a, int b){
        if (a>b)
            return b;
        else
            return a;
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
