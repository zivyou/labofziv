#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *myHead = new ListNode(INT_MIN);
        ListNode *right = head;

        while (right){
            if (myHead->next == NULL){
                ListNode *t = right;
                right = right->next;
                t->next = NULL;
                myHead->next = t;
            }else{
                ListNode *t = right;
                right = right->next;
                t->next = NULL;

                ListNode *lt = myHead;
                while (lt->next){
                    if (lt->val <= t->val && t->val <= lt->next->val)
                        break;
                    lt = lt->next;
                }
                if (!lt->next)
                    lt->next = t;
                else{
                    t->next = lt->next;
                    lt->next = t;
                }
            }
        }
        return myHead->next;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
