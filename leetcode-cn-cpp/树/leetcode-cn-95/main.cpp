#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution2 {
public:
  void rawGenerateTrees(vector<TreeNode*>& results, vector<int> data, TreeNode* &tmpRe) {
    if (!data.size()) {
      results.push_back(tmpRe);
    }

    for (int i=0; i<data.size(); i++) {
      vector<int> newData(data);
      newData.erase(data.begin()+i);
      if (tmpRe == nullptr) {
        tmpRe = new TreeNode(data[i]);
      } else {
        TreeNode* t = tmpRe;
        TreeNode* pre = nullptr;
        while (t) {
          if (data[i] < t->val) {
            pre = t;
            t = t->left;
          } else {
            pre = t;
            t = t->right;
          }
        }
        if (data[i] < pre->val) {
          pre->left = new TreeNode(data[i]);
        } else {
          pre->right = new TreeNode(data[i]);
        }
      }
      rawGenerateTrees(results, newData, tmpRe);
    }
  }
  vector<TreeNode*> generateTrees(int n) {
    vector<int> data;
    for (int i=1; i<=n; i++) data.push_back(i);
    vector<TreeNode*> results;
    TreeNode* tmpRe = nullptr;
    rawGenerateTrees(results, data, tmpRe);
    return results;
  }
private:
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
    Solution2 s;
    re = s.generateTrees(3);
    cout << re.size() << endl;
    return 0;
}
