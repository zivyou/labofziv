#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if (!root)
            return 0;
        q.push(root);
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        int level = 0;
        while (!q.empty()){
            TreeNode *n = q.front();
            q.pop();
            currentLevelCount --;

            if (n->left){
                q.push(n->left);
                nextLevelCount++;
            }

            if (n->right){
                q.push(n->right);
                nextLevelCount++;
            }
            if (currentLevelCount == 0){
                level++;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }

        return level;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
