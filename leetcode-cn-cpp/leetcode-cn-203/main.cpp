#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        ListNode * myHead = new ListNode(-1);
        myHead->next = head;
        ListNode *re = myHead;
        while (myHead->next){
            if (val == myHead->next->val){
                ListNode *toBeDel = myHead->next;
                myHead->next = myHead->next->next;
                delete toBeDel;
            }else
                myHead = myHead->next;
        }

        return re->next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
