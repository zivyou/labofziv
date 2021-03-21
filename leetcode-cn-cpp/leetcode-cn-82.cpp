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
        ListNode *pre = myHead;
        int flag = 0;
        while (t->next){
            if (t == myHead){
                t = t->next;
                continue;
            }
            if (t->val == t->next->val){
                ListNode * tt = t->next;
                t->next = t->next->next;
                delete tt;
                flag = 1;
            }else{
                if (flag){
                    ListNode *tt = pre->next;
                    pre->next = tt->next;
                    delete tt;
                    flag = 0;
                }else
                    pre = t;
                t = t->next;
            }
        }
        if (flag){
            ListNode *tt = pre->next;
            pre->next = tt->next;
            delete tt;
        }
        return myHead->next;
    }
};

int main(){
    return 0;
}