#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct TreeNode {
 int val;
 struct TreeNode *left;
 struct TreeNode *right;
 TreeNode(int a) { val = a; left = nullptr; right = nullptr; }
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    std::vector<int> preorderTraversal(TreeNode* root) {
        // write code here
        //
      std::vector<int> result;
      std::stack<TreeNode*> st;

      TreeNode* t = root;
      while (!st.empty() || t) {
        result.push_back(t->val);
        if (t->right) {
          st.push(t->right);
        }
        if (t->left) {
          st.push(t->left);
        }
        if (!st.empty()) {
          t = st.top();
          st.pop();
        } else break;
      }

      return result;
    }
};

int main() {
  TreeNode* tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->left->left = new TreeNode(4);

  Solution s;
  std::vector<int> result = s.preorderTraversal(tree);
  for (auto elem : result) {
    std::cout<<elem<<" ";
  }
  std::cout<<std::endl;
}
