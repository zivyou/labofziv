#include <cstdio>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
private:
    TreeNode* r = nullptr;
    void preOrder(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            root->left->val = root->val*2 + 1;
            preOrder(root->left);
        }
        if (root->right != nullptr) {
            root->right->val = root->val*2 + 2;
            preOrder(root->right);
        }

    }
    int pow2(int p) {
        if (p<=0) return 0;
        return 1<<p;
    }
    int f(int a, int currentLevel, int targetLevel) {
        a = 2*a+1; currentLevel++;
        while (currentLevel<targetLevel) {
            a=2*a+2;
            currentLevel++;
        }
        return a;
    }
    bool find(TreeNode* root, int target, int currentLevel, int targetLevel) {
        if (root == nullptr) return false;
        if (root->val == target) return true;
        if (currentLevel == targetLevel) return root->val == target;
        auto x = f(root->val, currentLevel, targetLevel);
        if (target <= x) {
            return find(root->left, target, currentLevel+1, targetLevel);
        } else {
            return find(root->right, target, currentLevel+1, targetLevel);
        }
    }
public:
    FindElements(TreeNode* root) {
        if (root == nullptr) return;
        root->val = 0;
        preOrder(root);
        r = root;
    }

    bool find(int target) {
        int l = 0;
        while (target > ((pow2(l)-1)*2)) {
            l++;
        }
        return find(r, target, 0, l);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

void init(TreeNode* root, int level) {
    if (level <= 0) return;
    root->left=new TreeNode(-1);
    root->right=new TreeNode(-1);
    init(root->left, level-1);
    init(root->right, level-1);
}

void init2(TreeNode* root) {
    root->val = 0;
    root->left = new TreeNode(1); root->right = new TreeNode(2);
    root->left->left=new TreeNode(3); root->left->right=new TreeNode(4);
}

void init3(TreeNode* root) {
    root->val = 0;
    root->right = new TreeNode(-1);
    root->right->left = new TreeNode(-1);
    root->right->left->left = new TreeNode(-1);
}

void display(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i=0; i<size && !q.empty(); i++) {
            auto e = q.front();
            q.pop();
            printf("%d ", e->val);
            if (e->left != nullptr) q.push(e->left);
            if (e->right != nullptr) q.push(e->right);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode;
    init3(root);
    display(root);
    FindElements findElements(root);
    display(root);
    printf("%d\n", findElements.find(5));
}
