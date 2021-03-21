#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        if (head == NULL || k == 0)
            return head;
        ListNode *h = head;
        while (h){
            length++;
            h = h->next;
        }

        int range = k%length;
        ListNode *re = new ListNode(-1);
        re->next = head;
        ListNode *front = re; ListNode *back = re;
        for (int i=0; i<range; i++)
            back = back->next;
        while (back->next){
            front = front -> next;
            back = back -> next;
        }

        back->next = re->next;
        re->next = front->next;
        front->next = NULL;

        return re->next;
    }
};

int main(){
    return 0;
}