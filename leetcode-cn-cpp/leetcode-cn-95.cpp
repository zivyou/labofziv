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
    int isValid(TreeNode *root){
        if (!root)
            return 1;
        if (root->left)
            if (root->left->val > root->val)
                return 0;
        if (root->right)
            if (root->right->val < root->val)
                return 0;
        if (!(isValid(root->left)))
            return 0;
        if (!(isValid(root->right)))
            return 0;

        return 1;
    }
    void build(vector<TreeNode*>& re, TreeNode *root, int leftList[2], int rightList[2], TreeNode *originRoot){
        if (leftList[0] == leftList[1] && rightList[0] == rightList[1] && isValid(originRoot)){
            re.push_back(originRoot);
            originRoot = NULL;
            return;
        }
        
        if (leftList[0] < leftList[1]){
            for (int i=leftList[0]; i<leftList[1]; i++){
                int newLeftList[2];int newRightList[2];
                newLeftList[0] = leftList[0];
                newLeftList[1] = i;
                newRightList[0] = i;
                newRightList[1] = leftList[1];
                root = new TreeNode(i);
                build(re, root->left, newLeftList, newRightList, originRoot);
            }
        }

        if (rightList[0] < rightList[1]){
            for (int i=rightList[0]; i<rightList[1]; i++){
                int newLeftList[2];int newRightList[2];
                newLeftList[0] = rightList[0];
                newLeftList[1] = i;
                newRightList[0] = i;
                newRightList[1] = rightList[1];
                root = new TreeNode(i);
                build(re, root->right, newLeftList, newRightList, originRoot);
            }
        }
    }

    void rawGenerateTrees(vector<TreeNode*> &re, int begin, int end){
        // [begin, end]
        
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> re;
        int leftList[2];
        int rightList[2];
        leftList[0] = 0;
        rightList[1] = n+1;
        for (int i=1; i<=n; i++){
            leftList[1] = i;
            rightList[0] = i+1;
            TreeNode *t = new TreeNode(i);
            build(re, t, leftList, rightList, t);
            delete t;
        }
        return re;
    }
};

int main(){
    return 0;
}