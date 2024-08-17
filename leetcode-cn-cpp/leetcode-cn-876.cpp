#include <cstdio>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto* p1 = head;
        auto* p2 = head;
        while (p1!=nullptr && p2!=nullptr && p2->next!=nullptr) {
            p1=p1->next;
            p2=p2->next->next;
        }
        return p1;
    }
};

int main(int argc, char* argv[]) {

}
