#include <iostream>
#include <vector>
#include <map>
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
    void getCol(map<int, vector<TreeNode*> > & m, TreeNode* root, int cur){
        if (!root)
            return;
        if (m.find(cur) != m.end()){
            m[cur].push_back(root);
        }else{
            vector<TreeNode*> v;
            v.push_back(root);
            m.insert(make_pair(cur, v));
        }

        if (root->left)
            getCol(m, root->left, cur-1);
        if (root->right)
            getCol(m, root->right, cur+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<TreeNode*> > m;
        int cur = 0;
        //getCol(m, root, cur);

        queue<pair<TreeNode*, int>> q;
        int t = 0;
        q.push(make_pair(root, t));
        while (!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int cur = p.second;
            TreeNode* n = p.first;
            if (n->left)
                q.push(make_pair(n->left, cur-1));
            if (n->right){
                q.push(make_pair(n->right, cur+1));
            }

            if (m.find(cur) != m.end()){
                m[cur].push_back(n);
            }else{
                vector<TreeNode*> v;
                v.push_back(n);
                m.insert(make_pair(cur, v));
            }
        }
        vector<vector<int>> re;
        for (auto pair : m){
            vector<int> v;
            for (auto node : pair.second){
                v.push_back(node->val);
            }
            re.push_back(v);
        }

        return re;
    }
};

int main(){
    return 0;
}