#include <cstdio>
#include <vector>
#include <climits>

/**
 * 线段树!
 */

using namespace std;

struct Node {
    struct Node* lp;
    struct Node* rp;
    int left, right;
    int data;
    int mark = 0;

    Node(int left, int right) : left(left), right(right) {
        lp = rp = nullptr;
        data = 0;
    }
};

class NumArray {
private:
    Node* root;

    void build(Node* node, vector<int>& nums) {
        if (node->left == node->right) {
            node->data = nums[node->left];
            return;
        }
        int mid = (node->left + node->right)/2;
        node->lp = new Node(node->left, mid);
        node->rp = new Node(mid+1, node->right);
        build(node->lp, nums);
        build(node->rp, nums);
        node->data = node->lp->data + node->rp->data;
    }

    int query(Node* node, int left, int right) {
        if (left<=node->left && node->right<=right) {
            return node->data;
        }
        if (left > node->right || right < node->left) {
            return 0;
        }
        return (query(node->lp, left, right) + query(node->rp, left, right));
    }

    void update(Node*node, int index, int val) {
        if (node->left == node->right) {
            if (node->left == index) {
                node->data = val;
                return;
            }
        }
        int mid = (node->left + node->right) / 2;
        if (index <= mid) update(node->lp, index, val);
        else update(node->rp, index, val);
        node->data = node->lp->data + node->rp->data;
    }

public:
    NumArray(vector<int>& nums) {
        root = new Node(0, nums.size()-1);
        build(root, nums);
    }

    void update(int index, int val) {
        update(root, index, val);
    }

    int sumRange(int left, int right) {
        return query(root, left, right);
    }
    ~NumArray() {
        delete root;
    }
};

int main() {
    vector<int> input({1, 3, 5});
    NumArray numArray(input);
    printf("sumRange[0, 2] is %d\n", numArray.sumRange(0, 2));
    printf("update nums[1] with 2; \n");
    numArray.update(1, 2);
    printf("sumRange[0, 2] is %d\n", numArray.sumRange(0, 2));
    return 0;
}