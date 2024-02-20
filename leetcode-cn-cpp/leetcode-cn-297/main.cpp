
#include <cstddef>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string preOrder(TreeNode* root) {
        if (root == nullptr) return "";
        std::stringstream ss;
        ss<<root->val; ss<<",";
        if (root->left) {
            ss<<preOrder(root->left);
        } else {
            ss<<"*,";
        }
        if (root->right) {
            ss<<preOrder(root->right);
        } else {
            ss<<"*,";
        }
        return ss.str();
    }

    pair<TreeNode*, int> _(vector<string>& data, int at) {
        if (at >= data.size()) return {nullptr, at};
        if (data[at] == "*") return {nullptr, at};
        auto value = stoi(data[at]);
        auto root = new TreeNode(value);
        int returnAt = at;
        if (at+1 < data.size()) {
            auto res = _(data, at+1);
            root->left = res.first;
            int pos = res.second;
            returnAt = pos;
            if (pos+1 < data.size()) {
                auto res2 = _(data, pos+1);
                root->right = res2.first;
                returnAt = res2.second;
            }
        }
        return {root, returnAt};
    }
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        return preOrder(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        vector<string> values;
        int i=0; int j=0;
        while (i<data.length() && j<data.length()) {
            if (data[j] == ',') {
                values.push_back(data.substr(i, j-i));
                i=j+1;
            }
            j++;
        }
        return _(values, 0).first;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Codec codec;
    auto s = codec.serialize(root);
    printf("%s\n", s.c_str());
    auto r =codec.deserialize("1,2,*,*,3,4,*,*,5,*,*,");
    printf("%d\n", r->val == root->val);
    printf("%d\n", r->left->val == root->left->val);
    printf("%d\n", r->right->val == root->right->val);
    printf("%d\n", r->right->left->val == root->right->left->val);
    printf("%d\n", r->right->right->val == root->right->right->val);
}
