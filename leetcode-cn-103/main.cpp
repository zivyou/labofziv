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
    void dumpData(vector<vector<int>> &re, vector<int> levelData, int dir){
        if (dir == 0){
            re.push_back(levelData);
            return;
        }else {
            vector<int> newData;
            for (int i=levelData.size()-1; i>=0; i--)
                newData.push_back(levelData[i]);
            re.push_back(newData);
            return;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> re;
        if (!root)
            return re;
        vector<int> levelData;
        int currentLevelCount = 1;
        int nextLevelCount = 0;
        int dir = 0; // 0 for left-to-right; 1 for right-to-left
        while (!q.empty()){
            TreeNode *n = q.front();
            q.pop();
            levelData.push_back(n->val);
            currentLevelCount--;

            if (n->left) {
                q.push(n->left);
                nextLevelCount++;
            }
            if (n->right) {
                q.push(n->right);
                nextLevelCount++;
            }

            if (currentLevelCount == 0){
                dumpData(re, levelData, dir);
                levelData.clear();
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
                dir = 1 - dir;
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
