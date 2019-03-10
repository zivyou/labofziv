#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *myHead = new ListNode(-1);
        myHead->next = head;
        ListNode *t = myHead;

        while (t->next){
            if (t == myHead){
                t = t->next;
                continue;
            }
            if (t->val == t->next->val){
                ListNode * tt = t->next;
                t->next = t->next->next;
                delete tt;
            }else
                t = t->next;
        }

        return myHead->next;
    }
};

int main(){

}