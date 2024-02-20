#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* rhead = new ListNode(-1); ListNode* lhead = new ListNode(-1);
        ListNode* t = head;
        while (t) {
            if (t->val >= x) {
                auto tt = t;
                t = t->next;
                tt->next = rhead->next;
                rhead->next = tt;
            } else {
                auto tt = t;
                t = t->next;
                tt->next = lhead->next;
                lhead->next = tt;
            }
        }
        t = lhead;
        while (t ->next) {
            t = t->next;
        }
        t->next=rhead->next;
        return lhead->next;
    }
};

int main(int argc, char* argv[]) {

}
