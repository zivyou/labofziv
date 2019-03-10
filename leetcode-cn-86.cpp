#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *leftHead = new ListNode(-1);
        ListNode *rightHead = new ListNode(-1);
        leftHead->next = head;
        ListNode *t = leftHead;
        ListNode *rightTail = rightHead;
        while (t->next){

            if (t->next->val >= x){
                ListNode * tt = t->next;
                t->next = t->next->next;
                rightTail->next = tt;
                tt->next = NULL;
                rightTail = rightTail->next;
            }else
                t = t->next;
        }

        t = leftHead;
        while (t->next){
            t = t->next;
        }
        t->next = rightHead->next;

        return leftHead->next;
    }
};

int  main(){

}