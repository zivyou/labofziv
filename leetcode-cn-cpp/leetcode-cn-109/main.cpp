#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void rawBuildTree(TreeNode *&root, ListNode *head, ListNode *tail){
         if (head == tail){
            root = NULL;
            return;
         }

         ListNode *faster = head;
         ListNode *slower = head;
         while (faster != tail && faster->next != tail){
            slower = slower->next;
            faster = faster->next->next;
         }

         root = new TreeNode(slower->val);
         //cout<<"root->val="<<root->val<<endl;
         rawBuildTree(root->left, head, slower);
         rawBuildTree(root->right, slower->next, tail);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        TreeNode *root;
        rawBuildTree(root, head, NULL);
        return root;
    }

    void print(TreeNode *root){
        if (!root) return;
        if (root->left)
            print(root->left);
        cout<<root->val<<" ";
        if (root->right)
            print(root->right);
    }
};

int main()
{
    vector<int> v({-10, -3, 0, 5, 9});
    ListNode *myHead = new ListNode(-1);
    ListNode *n = myHead;
    for (int i=0;i<v.size(); i++){
        n->next = new ListNode(v[i]);
        n = n->next;
    }
    Solution s;
    TreeNode * root = s.sortedListToBST(myHead->next);
    s.print(root);
    cout << "Hello world!" << endl;
    return 0;
}
