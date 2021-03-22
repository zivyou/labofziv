#include <iostream>
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
    void search(TreeNode* root, TreeNode* p, vector<TreeNode*> &path, bool& found){
        if (!root)
            return;
        
        path.push_back(root);
        if (root == p){
            found = true;
            return;
        }

        if (!found && root->left){
            search(root->left, p, path, found);
        }
    
        if (!found)
        while (path[path.size()-1] != root)
            path.pop_back();

        if (!found && root->right){
            search(root->right, p, path, found);
        }
        if (!found)
        while (path[path.size()-1] != root)
            path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        bool found1 = false;
        bool found2 = false;
        search(root, p, path1, found1);
        search(root, q, path2, found2);

        for (auto node : path1){
            cout<<node->val<<", ";
        }
        cout<<endl;

        for (auto node : path2){
            cout<<node->val<<", ";
        }
        cout<<endl;
        if (!(found1 && found2))
            return nullptr;
        
        TreeNode* re = root;
        for (int i=0; i<min<int>(path1.size(), path2.size()); i++){
            if (path1[i] != path2[i])
                return re;
            re = path1[i];
        }

        return re;
    }
};

int main(){
    return 0;
}