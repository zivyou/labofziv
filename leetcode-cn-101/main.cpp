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
    bool isSymmetricVector(vector<TreeNode *> v){
        if (v.size() <= 1)
            return true;
        if (v.size() % 2)
            return false;
        int i=0; int j=v.size()-1;
        while (i<j){
            if (v[i] == v[j] && v[i]==NULL){
                i++; j--;
                continue;
            }
            if (!v[i] || !v[j])
                return false;
            if (v[i]->val != v[j]->val)
                return false;
            i++; j--;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode *> q;
        vector<TreeNode *> v;
        q.push(root);
        TreeNode *n;

        int currentLevelCount = 1;
        int nextLevelCount = 0;
        while (!q.empty()){
            n = q.front();
            q.pop();
            v.push_back(n);
            currentLevelCount--;

            if (n){
                q.push(n->left);
                q.push(n->right);
                nextLevelCount += 2;
            }

            if (currentLevelCount == 0){
                if (isSymmetricVector(v)){
                    v.clear();
                }else
                    return false;
                currentLevelCount = nextLevelCount;
                nextLevelCount = 0;
            }
        }

        return true;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
