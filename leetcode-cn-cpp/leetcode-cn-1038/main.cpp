#include <cstdio>
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
    vector<TreeNode*> nodes;
private:
    void travelsal(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            nodes.push_back(root);
            return;
        }
        if (root->left != nullptr) {
            travelsal(root->left);
        }
        nodes.push_back(root);
        if (root->right != nullptr) {
            travelsal(root->right);
        }
    }
    void _(TreeNode* root) {
        travelsal(root);
        // for (int i=0; i<nodes.size(); i++) {
        //     printf("%d ", nodes[i]->val);
        // }
        // printf("\n");
        for (int x=nodes.size()-1; x>0; x--) {
            nodes[x-1]->val = nodes[x]->val + nodes[x-1]->val;
        }
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        _(root);
        return root;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);
    Solution s;
    printf("=============================: %d\n", s.bstToGst(root)->val);
}
