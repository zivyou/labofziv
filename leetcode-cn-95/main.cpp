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
    vector<TreeNode*> rawGenerateTrees(int begin, int end){
        vector<TreeNode*> re;
        if (begin > end){
            re.push_back(NULL);
            return re;
        }

        for (int i=begin; i<=end; i++){
            vector<TreeNode*> leftTrees = rawGenerateTrees(begin, i-1);
            vector<TreeNode*> rightTrees = rawGenerateTrees(i+1, end);

            for (int j=0; j<leftTrees.size(); j++)
                for (int k=0; k<rightTrees.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    re.push_back(root);
                }
        }
        return re;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> re;
        re = rawGenerateTrees(1, n);
        return re;
    }
};

int main()
{
    vector<TreeNode*> re;
    Solution s;
    re = s.generateTrees(3);
    cout << re.size() << endl;
    return 0;
}
