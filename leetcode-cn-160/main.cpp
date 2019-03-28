#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a = headA;
        ListNode * b = headB;
        if (headA == headB)
            return headA;
        if (!headA || !headB)
            return NULL;
        while (a->next && b->next){
            if (a->next == b->next)
                return a->next;
            a = a->next;
            b = b->next;
        }

        if (a->next == NULL && b->next == NULL){
            return NULL;
        }

        if (a->next == NULL){
            while (b->next){
                headB = headB->next;
                b = b->next;
            }
        }else if (b->next == NULL){
            while (a->next){
                headA = headA->next;
                a = a->next;
            }

        }else
            return NULL;
        while (headA && headB){
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
