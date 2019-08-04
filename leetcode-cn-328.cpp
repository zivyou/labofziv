#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        ListNode* n = head;
        int count = 1;
        while (n){
            if (count & 1){
                oddTail->next = n;
                oddTail = oddTail->next;
            }else{
                evenTail->next = n;
                evenTail = evenTail->next;
            }
            n = n->next;
            count++;
        }

        evenTail->next = NULL;
        oddTail->next = evenHead->next;
        return oddHead->next;
        
    }
};
int main(){
    return 0;
}