#include <cstdio>
#include <vector>
#include <unistd.h>
#include <unordered_set>
#include <string>

namespace {

    template<typename T>
    struct Node {
        struct Node *lp;
        struct Node *rp;
        int left, right;
        std::unordered_set<T> data;
        std::unordered_set<T> mark = {};
        std::unordered_set<T> deleted = {};;

        Node(int left, int right) : left(left), right(right) {
            lp = rp = nullptr;
            data = {};
        }
        ~Node() {
            delete lp;
            delete rp;
            lp = nullptr; rp = nullptr;
        }
    };

    template<typename T>
    class SegmentTree {
    private:
        Node<T> *root;

        inline std::unordered_set<T> merge(std::unordered_set<T>& x, std::unordered_set<T>& y) {
            std::unordered_set<T> unorderedSet;
            unorderedSet.insert(x.begin(), x.end());
            unorderedSet.insert(y.begin(), y.end());
            return unorderedSet;
        }

        void build(Node<T> *node, std::vector<T> &nums) {
            if (node->left == node->right) {
                node->data.insert(nums[node->left]);
                return;
            }
            int mid = (node->left + node->right) / 2;
            node->lp = new Node<T>(node->left, mid);
            node->rp = new Node<T>(mid + 1, node->right);
            build(node->lp, nums);
            build(node->rp, nums);
            // 合并两个集合给到node->data
            node->data = merge(node->lp->data, node->rp->data);
        }

        void build(Node<T>* node) {
            if (node->left == node->right) {
                return;
            }
            int mid = (node->left + node->right) / 2;
            node->lp = new Node<T>(node->left, mid);
            node->rp = new Node<T>(mid + 1, node->right);
            build(node->lp);
            build(node->rp);
        }

        std::unordered_set<T> query(Node<T> *node, int left, int right) {
            if (left <= node->left && node->right <= right) {
                pushDown(node);
                return node->data;
            }
            if (left > node->right || right < node->left) {
                return {};
            }
            pushDown(node);
            auto x = query(node->lp, left, right);
            auto y = query(node->rp, left, right);
            return merge(x, y);
        }

        void mergeInvoke(std::unordered_set<T>& ret, std::unordered_set<T>& input) {
            ret.insert(input.begin(), input.end());
        }

        void diffSetInvoke(std::unordered_set<T>& a, std::unordered_set<T>& b) {
            for (const auto& x : b) a.erase(x);
        }

        void pushDown(Node<T>* node) {
            if (node->mark.size() > 0 && node->lp && node->rp) {
                mergeInvoke(node->lp->mark, node->mark);
                mergeInvoke(node->rp->mark, node->mark);
                mergeInvoke(node->lp->data, node->mark);
                mergeInvoke(node->rp->data, node->mark);
                node->mark.clear();
            }

            if (!node->deleted.empty()) {
                diffSetInvoke(node->lp->data, node->deleted);
                diffSetInvoke(node->rp->data, node->deleted);
                mergeInvoke(node->lp->deleted, node->deleted);
                mergeInvoke(node->rp->deleted, node->deleted);
                node->deleted.clear();
            }
        }

        bool insert(Node<T>* node, int index, T val) {
            if (node->left == node->right) {
                if (node->left == index) {
                    if (node->data.size() == 0) {
                        node->data.insert(val);
                        node->mark.insert(val);
                        pushDown(node);
                        return true;
                    } else
                        return false;
                }
            }
            int mid = (node->left + node->right) / 2;
            if (index <= mid) {
                return insert(node->lp, index, val);
            } else {
                return insert(node->rp, index, val);
            }
        }

        bool insert(Node<T>* node, int from, int to, T val) {
            if (node->left <= from && node->right >= to) {
                if (node->data.size() == 0) {
                    node->data.insert(val);
                    node->mark.insert(val);
                    pushDown(node);
                    return true;
                } else
                    return false;
            }

            int mid = (node->left + node->right) / 2;
            if (to <= mid) {
                return insert(node->lp, from, to, val);
            } else if (mid < from) {
                return insert(node->rp, from, to, val);
            } else {
                return insert(node->lp, from, mid, val) && insert(node->rp, mid+1, to, val);
            }
        }

        bool remove(Node<T>* node, int from, int to, T val) {
            if (node->left <= from && node->right >= to) {
                auto x = node->data.erase(val);
                node->deleted.insert(val);
                pushDown(node);
                return x > 0;
            }
            int mid = (node->left + node->right) / 2;
            if (to <= mid) {
                return remove(node->lp, from, to, val);
            } else if (mid < from) {
                return remove(node->rp, from, to, val);
            } else {
                return remove(node->lp, from, mid, val) || remove(node->rp, mid+1, to, val);
            }
        }

    public:
        SegmentTree(std::vector<T> &datas) {
            root = new Node<T>(0, datas.size() - 1);
            printf("before build segment tree!\n");
            build(root, datas);
        }

        SegmentTree(int range) {
            root = new Node<T>(0, range-1);
            build(root);
        }

        bool insert(int index, T val) {
            return insert(root, index, val);
        }

        bool insert(int from, int to, T val) {
            auto x = query(from, to);
            if (x.size() > 0) return false;
            return insert(root, from, to, val);
        }

        std::unordered_set<T> query(int begin, int end) {
            return query(root, begin, end);
        }

        bool remove(int from, int to, T val) {
            return remove(root, from, to, val);
        }

        ~SegmentTree() {
            delete root;
        }
    };
};

int main() {
    SegmentTree<std::string> segmentTree(60*60*24);
    bool result1 = segmentTree.insert(0, 1,"droneSn1");
    bool result2 = segmentTree.insert(0, 1,"droneSn1");
    printf("result1 = %d, result2 = %d\n", result1, result2);
    auto results = segmentTree.query(0, 1);
    for (const auto & x : results) {
        printf("%s\n", x.c_str());
    }

    printf("========================================\n");
    segmentTree.remove(0, 1, "droneSn1");
    results = segmentTree.query(0, 1);
    for (const auto & x : results) {
        printf("%s\n", x.c_str());
    }
    pause();
    return 0;
}
