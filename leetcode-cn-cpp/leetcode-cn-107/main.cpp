#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> re;
        if (!root)
            return re;
        queue<TreeNode *> q;
        vector<TreeNode *> v;

        q.push(root);
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        vector<int> levelData;

        while (!q.empty()){
            TreeNode *n = q.front();
            q.pop();
            levelData.push_back(n->val);
            currentLevelCount--;
            if (n->left){
                q.push(n->left);
                nextLevelCount++;
            }

            if (n->right){
                q.push(n->right);
                nextLevelCount++;
            }

            if (currentLevelCount == 0){
                re.insert(re.begin(), levelData);
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
                levelData.clear();
            }
        }

        return re;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
