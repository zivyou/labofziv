#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        auto* myHead = new ListNode(-1);
        ListNode* t = myHead;
        while (l1 || l2) {
            if (l1 && l2) {
                auto minNode = l1->val < l2->val ? l1 : l2;
                t->next = minNode;
                t = t->next;
//                t->next = nullptr;
                if (minNode == l1) l1 = l1->next;
                if (minNode == l2) l2 = l2->next;
            } else if (!l1) {
                t->next = l2;
                break;
            } else {
                t->next = l1;
                break;
            }
        }
        t = myHead->next;
        delete myHead;
        return t;
    }

    std::pair<ListNode*, ListNode*> split(ListNode* head) {
        ListNode* myHead = new ListNode(-1);
        myHead->next = head;
        ListNode* l1 = myHead;
        ListNode* l2 = myHead;
        while (l1 && l2 && l2->next) {
            l1 = l1->next;
            l2 = l2->next->next;
        }
        l2 = l1->next;
        l1->next = nullptr;
        return std::make_pair(myHead->next, l2);
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        if (head->next == nullptr) return head;
        auto [l1, l2] = split(head);
        l1 = sortList(l1);
        l2 = sortList(l2);
        auto re = mergeList(l1, l2);
        return re;
    }

    void print(ListNode *head){
        while (head){
            cout<<"node: "<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }
};

static ListNode* arrayToList(int a[]) {
    auto *t = new ListNode(-1);
    auto re = t;
    for (int i=0; i<sizeof(a)/4; i++){
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    return re->next;
}

//int main() {
//    int a[] = {2, 4};
//    int b[] = {1, 3};
//    Solution s;
//    auto t = s.mergeList(arrayToList(a), arrayToList(b));
//    s.print(t);
//}


int main()
{
    int a[] = {4,2,1,3,8,5,7,6};
    ListNode *myHead = new ListNode(-1);
    ListNode *t = myHead;
    for (int i=0; i<sizeof(a)/4; i++){
        t->next = new ListNode(a[i]);
        t = t->next;
    }
    Solution s;
    s.print(myHead->next);
    ListNode *newHead = s.sortList(myHead->next);
    s.print(newHead);
    return 0;
}